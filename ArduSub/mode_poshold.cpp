// ArduSub position hold flight mode
// GPS required
// Jacob Walser August 2016

#include "Sub.h"

#if POSHOLD_ENABLED

// poshold_init - initialise PosHold controller
bool ModePoshold::init(bool ignore_checks)
{
    // fail to initialise PosHold mode if no GPS lock
    if (!sub.position_ok()) {
        return false;
    }

    // initialize vertical speeds and acceleration
    position_control->set_max_speed_accel_xy(sub.wp_nav.get_default_speed_xy(), sub.wp_nav.get_wp_acceleration());
    position_control->set_correction_speed_accel_xy(sub.wp_nav.get_default_speed_xy(), sub.wp_nav.get_wp_acceleration());
    position_control->set_max_speed_accel_z(-sub.get_pilot_speed_dn(), g.pilot_speed_up, g.pilot_accel_z);
    position_control->set_correction_speed_accel_z(-sub.get_pilot_speed_dn(), g.pilot_speed_up, g.pilot_accel_z);

    // initialise position and desired velocity
    position_control->init_xy_controller_stopping_point();
    position_control->init_z_controller();

    // Stop all thrusters
    attitude_control->set_throttle_out(0.5f ,true, g.throttle_filt);
    attitude_control->relax_attitude_controllers();
    position_control->relax_z_controller(0.5f);

    sub.last_pilot_heading = ahrs.yaw_sensor;

    return true;
}

// poshold_run - runs the PosHold controller
// should be called at 100hz or more
void ModePoshold::run()
{
    uint32_t tnow = AP_HAL::millis();
    // When unarmed, disable motors and stabilization
    if (!motors.armed()) {
        motors.set_desired_spool_state(AP_Motors::DesiredSpoolState::GROUND_IDLE);
        // Sub vehicles do not stabilize roll/pitch/yaw when not auto-armed (i.e. on the ground, pilot has never raised throttle)
        attitude_control->set_throttle_out(0.5f ,true, g.throttle_filt);
        attitude_control->relax_attitude_controllers();
        position_control->init_xy_controller_stopping_point();
        position_control->relax_z_controller(0.5f);
        sub.last_pilot_heading = ahrs.yaw_sensor;
        return;
    }

    // set motors to full range
    motors.set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);

    ///////////////////////
    // update xy outputs //
    float pilot_lateral = channel_lateral->norm_input();
    float pilot_forward = channel_forward->norm_input();

    float lateral_out = 0;
    float forward_out = 0;

    if (sub.position_ok()) {
        // Allow pilot to reposition the sub
        if (fabsf(pilot_lateral) > 0.1 || fabsf(pilot_forward) > 0.1) {
            position_control->init_xy_controller_stopping_point();
        }
        sub.translate_pos_control_rp(lateral_out, forward_out);
        position_control->update_xy_controller();
    } else {
        position_control->init_xy_controller_stopping_point();
    }
    motors.set_forward(forward_out + pilot_forward);
    motors.set_lateral(lateral_out + pilot_lateral);
    /////////////////////
    // Update attitude //

    // get pilot's desired yaw rate
    float yaw_input = channel_yaw->pwm_to_angle_dz_trim(channel_yaw->get_dead_zone() * sub.gain, channel_yaw->get_radio_trim());
    float target_yaw_rate = sub.get_pilot_desired_yaw_rate(yaw_input);

    // convert pilot input to lean angles
    // To-Do: convert get_pilot_desired_lean_angles to return angles as floats
    float target_roll, target_pitch;
    sub.get_pilot_desired_lean_angles(channel_roll->get_control_in(), channel_pitch->get_control_in(), target_roll, target_pitch, sub.aparm.angle_max);

    // update attitude controller targets
    if (!is_zero(target_yaw_rate)) { // call attitude controller with rate yaw determined by pilot input
        attitude_control->input_euler_angle_roll_pitch_euler_rate_yaw(target_roll, target_pitch, target_yaw_rate);
        sub.last_pilot_heading = ahrs.yaw_sensor;
        sub.last_pilot_yaw_input_ms = tnow; // time when pilot last changed heading

    } else { // hold current heading

        // this check is required to prevent bounce back after very fast yaw manoeuvres
        // the inertia of the vehicle causes the heading to move slightly past the point when pilot input actually stopped
        if (tnow < sub.last_pilot_yaw_input_ms + 250) { // give 250ms to slow down, then set target heading
            target_yaw_rate = 0; // Stop rotation on yaw axis

            // call attitude controller with target yaw rate = 0 to decelerate on yaw axis
            attitude_control->input_euler_angle_roll_pitch_euler_rate_yaw(target_roll, target_pitch, target_yaw_rate);
            sub.last_pilot_heading = ahrs.yaw_sensor; // update heading to hold

        } else { // call attitude controller holding absolute absolute bearing
            attitude_control->input_euler_angle_roll_pitch_yaw(target_roll, target_pitch, sub.last_pilot_heading, true);
        }
    }

    // Update z axis //
    control_depth();
}
#endif  // POSHOLD_ENABLED
