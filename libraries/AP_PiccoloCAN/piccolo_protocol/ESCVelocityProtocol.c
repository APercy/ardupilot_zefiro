// ESCVelocityProtocol.c was generated by ProtoGen version 3.5.c

/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Oliver Walters / Currawong Engineering Pty Ltd
 */

#include "ESCVelocityProtocol.h"

/*!
 * \brief Lookup label for 'ESCOperatingModes' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCOperatingModes_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_MODE_STANDBY:
        return "ESC_MODE_STANDBY";
    case ESC_MODE_PWM:
        return "ESC_MODE_PWM";
    case ESC_MODE_RPM:
        return "ESC_MODE_RPM";
    case ESC_MODE_VOLT:
        return "ESC_MODE_VOLT";
    case ESC_VALID_MODES:
        return "ESC_VALID_MODES";
    }
}


/*!
 * \brief Lookup label for 'ESCCommandSources' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCCommandSources_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_COMMAND_SOURCE_NONE:
        return "ESC_COMMAND_SOURCE_NONE";
    case ESC_COMMAND_SOURCE_CAN:
        return "ESC_COMMAND_SOURCE_CAN";
    case ESC_COMMAND_SOURCE_PWM:
        return "ESC_COMMAND_SOURCE_PWM";
    }
}


/*!
 * \brief Lookup label for 'ESCMotorTemperatureSensor' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCMotorTemperatureSensor_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_MOTOR_TEMP_SENSOR_OFF:
        return "ESC_MOTOR_TEMP_SENSOR_OFF";
    case ESC_MOTOR_TEMP_SENSOR_KTY84:
        return "ESC_MOTOR_TEMP_SENSOR_KTY84";
    case ESC_MOTOR_TEMP_SENSOR_KTY83:
        return "ESC_MOTOR_TEMP_SENSOR_KTY83";
    case ESC_MOTOR_TEMP_SENSOR_NTC_SH:
        return "ESC_MOTOR_TEMP_SENSOR_NTC_SH";
    case ESC_MOTOR_TEMP_SENSOR_NTC_BETA:
        return "ESC_MOTOR_TEMP_SENSOR_NTC_BETA";
    }
}


/*!
 * \brief Lookup label for 'ESCMotorDirection' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCMotorDirection_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_MOTOR_DIR_ABC:
        return "ESC_MOTOR_DIR_ABC";
    case ESC_MOTOR_DIR_ACB:
        return "ESC_MOTOR_DIR_ACB";
    case ESC_MOTOR_DIR_OTHER:
        return "ESC_MOTOR_DIR_OTHER";
    }
}


/*!
 * \brief Lookup label for 'ESCHallSensorMode' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCHallSensorMode_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_HALL_MODE_SENSORLESS:
        return "ESC_HALL_MODE_SENSORLESS";
    case ESC_HALL_MODE_SENSORED:
        return "ESC_HALL_MODE_SENSORED";
    case ESC_HALL_MODE_HYBRID:
        return "ESC_HALL_MODE_HYBRID";
    }
}


/*!
 * \brief Lookup label for 'ESCAFWModes' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCAFWModes_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_AFW_MODE_OFF:
        return "ESC_AFW_MODE_OFF";
    case ESC_AFW_MODE_ON:
        return "ESC_AFW_MODE_ON";
    case ESC_AFW_MODE_DYNAMIC:
        return "ESC_AFW_MODE_DYNAMIC";
    case ESC_AFW_MODE_OTHER:
        return "ESC_AFW_MODE_OTHER";
    }
}


/*!
 * \brief Lookup label for 'ESCPWMFreqModes' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCPWMFreqModes_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_PWM_FREQ_FIXED:
        return "ESC_PWM_FREQ_FIXED";
    case ESC_PWM_FREQ_RAMP:
        return "ESC_PWM_FREQ_RAMP";
    case ESC_PWM_FREQ_OTHER:
        return "ESC_PWM_FREQ_OTHER";
    }
}


/*!
 * \brief Lookup label for 'ESCTimingAdvanceModes' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCTimingAdvanceModes_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_TIMING_ADVANCE_MODE_FIXED:
        return "ESC_TIMING_ADVANCE_MODE_FIXED";
    case ESC_TIMING_ADVANCE_MODE_RAMP:
        return "ESC_TIMING_ADVANCE_MODE_RAMP";
    case ESC_TIMING_ADVANCE_MODE_OTHER:
        return "ESC_TIMING_ADVANCE_MODE_OTHER";
    }
}


/*!
 * \brief Lookup label for 'ESCProtectionActions' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCProtectionActions_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_PROTECTION_WARNING:
        return "ESC_PROTECTION_WARNING";
    case ESC_PROTECTION_FOLDBACK:
        return "ESC_PROTECTION_FOLDBACK";
    case ESC_PROTECTION_DISABLE:
        return "ESC_PROTECTION_DISABLE";
    case ESC_PROTECTION_INVALID:
        return "ESC_PROTECTION_INVALID";
    }
}


/*!
 * \brief Lookup label for 'ESCBeepModes' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCBeepModes_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_BEEP_NONE:
        return "ESC_BEEP_NONE";
    case ESC_BEEP_STATUS:
        return "ESC_BEEP_STATUS";
    case ESC_BEEP_ERROR:
        return "ESC_BEEP_ERROR";
    case ESC_BEEP_ALL:
        return "ESC_BEEP_ALL";
    }
}


/*!
 * \brief Lookup label for 'ESCStandbyCause' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCStandbyCause_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_STANDBY_CAUSE_CMD:
        return "ESC_STANDBY_CAUSE_CMD";
    case ESC_STANDBY_CAUSE_INHIBIT:
        return "ESC_STANDBY_CAUSE_INHIBIT";
    case ESC_STANDBY_CAUSE_TIMEOUT:
        return "ESC_STANDBY_CAUSE_TIMEOUT";
    case ESC_STANDBY_CAUSE_HALL_SENSOR_ERROR:
        return "ESC_STANDBY_CAUSE_HALL_SENSOR_ERROR";
    case ESC_STANDBY_CAUSE_INVALID_CMD:
        return "ESC_STANDBY_CAUSE_INVALID_CMD";
    case ESC_STANDBY_CAUSE_PWM_ARM:
        return "ESC_STANDBY_CAUSE_PWM_ARM";
    case ESC_STANDBY_CAUSE_FAILED_START:
        return "ESC_STANDBY_CAUSE_FAILED_START";
    case ESC_STANDBY_CAUSE_MIN_CMD:
        return "ESC_STANDBY_CAUSE_MIN_CMD";
    case ESC_STANDBY_CAUSE_FAILED_RESYNC:
        return "ESC_STANDBY_CAUSE_FAILED_RESYNC";
    case ESC_STANDBY_CAUSE_UNEXPECTED:
        return "ESC_STANDBY_CAUSE_UNEXPECTED";
    case ESC_STANDBY_CAUSE_RESET:
        return "ESC_STANDBY_CAUSE_RESET";
    }
}


/*!
 * \brief Lookup label for 'ESCDisableCause' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCDisableCause_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_DISABLE_CAUSE_NONE:
        return "ESC_DISABLE_CAUSE_NONE";
    case ESC_DISABLE_CAUSE_CAN_CMD:
        return "ESC_DISABLE_CAUSE_CAN_CMD";
    case ESC_DISABLE_CAUSE_PWM_TIMEOUT:
        return "ESC_DISABLE_CAUSE_PWM_TIMEOUT";
    case ESC_DISABLE_CAUSE_HARDWARE:
        return "ESC_DISABLE_CAUSE_HARDWARE";
    case ESC_DISABLE_CAUSE_OVERCURRENT:
        return "ESC_DISABLE_CAUSE_OVERCURRENT";
    case ESC_DISABLE_CAUSE_OVERSPEED:
        return "ESC_DISABLE_CAUSE_OVERSPEED";
    case ESC_DISABLE_CAUSE_OVERTEMP:
        return "ESC_DISABLE_CAUSE_OVERTEMP";
    case ESC_DISABLE_CAUSE_UNDERVOLTAGE:
        return "ESC_DISABLE_CAUSE_UNDERVOLTAGE";
    case ESC_DISABLE_CAUSE_FAILED_START:
        return "ESC_DISABLE_CAUSE_FAILED_START";
    case ESC_DISABLE_CAUSE_COMMUTATION_ERROR:
        return "ESC_DISABLE_CAUSE_COMMUTATION_ERROR";
    case ESC_DISABLE_CAUSE_PHASE_VOLTAGE:
        return "ESC_DISABLE_CAUSE_PHASE_VOLTAGE";
    case ESC_DISABLE_CAUSE_REGEN_CURRENT:
        return "ESC_DISABLE_CAUSE_REGEN_CURRENT";
    case ESC_DISABLE_CAUSE_INVALID_STATE:
        return "ESC_DISABLE_CAUSE_INVALID_STATE";
    case ESC_DISABLE_CAUSE_RESET:
        return "ESC_DISABLE_CAUSE_RESET";
    }
}


/*!
 * \brief Lookup label for 'ESCMotorOffCause' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCMotorOffCause_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_MOTOR_OFF_STANDBY:
        return "ESC_MOTOR_OFF_STANDBY";
    case ESC_MOTOR_OFF_BEEP:
        return "ESC_MOTOR_OFF_BEEP";
    case ESC_MOTOR_OFF_INITIALISE:
        return "ESC_MOTOR_OFF_INITIALISE";
    case ESC_MOTOR_OFF_INHIBITED:
        return "ESC_MOTOR_OFF_INHIBITED";
    case ESC_MOTOR_OFF_THROTTLE_MIN:
        return "ESC_MOTOR_OFF_THROTTLE_MIN";
    case ESC_MOTOR_OFF_NOT_RUNNING:
        return "ESC_MOTOR_OFF_NOT_RUNNING";
    case ESC_MOTOR_OFF_FAILED_START:
        return "ESC_MOTOR_OFF_FAILED_START";
    case ESC_MOTOR_OFF_INVALID:
        return "ESC_MOTOR_OFF_INVALID";
    }
}


/*!
 * \brief Lookup label for 'ESCFailedStartCause' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCFailedStartCause_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case ESC_FAILED_START_CAUSE_RESET:
        return "ESC_FAILED_START_CAUSE_RESET";
    case ESC_FAILED_START_CAUSE_TIMEOUT:
        return "ESC_FAILED_START_CAUSE_TIMEOUT";
    case ESC_FAILED_START_CAUSE_OVERSPEED:
        return "ESC_FAILED_START_CAUSE_OVERSPEED";
    case ESC_FAILED_START_CAUSE_OVERCURRENT:
        return "ESC_FAILED_START_CAUSE_OVERCURRENT";
    case ESC_FAILED_START_CAUSE_SPIN_REVERSED:
        return "ESC_FAILED_START_CAUSE_SPIN_REVERSED";
    case ESC_FAILED_START_CAUSE_SPIN_TOO_FAST:
        return "ESC_FAILED_START_CAUSE_SPIN_TOO_FAST";
    case ESC_FAILED_START_CAUSE_INVALID:
        return "ESC_FAILED_START_CAUSE_INVALID";
    }
}


/*!
 * \brief Lookup label for 'ESCMultiCommandPackets' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCMultiCommandPackets_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case PKT_ESC_SETPOINT_1:
        return "PKT_ESC_SETPOINT_1";
    case PKT_ESC_SETPOINT_2:
        return "PKT_ESC_SETPOINT_2";
    case PKT_ESC_SETPOINT_3:
        return "PKT_ESC_SETPOINT_3";
    case PKT_ESC_SETPOINT_4:
        return "PKT_ESC_SETPOINT_4";
    case PKT_ESC_SETPOINT_5:
        return "PKT_ESC_SETPOINT_5";
    case PKT_ESC_SETPOINT_6:
        return "PKT_ESC_SETPOINT_6";
    case PKT_ESC_SETPOINT_7:
        return "PKT_ESC_SETPOINT_7";
    case PKT_ESC_SETPOINT_8:
        return "PKT_ESC_SETPOINT_8";
    case PKT_ESC_SETPOINT_9:
        return "PKT_ESC_SETPOINT_9";
    case PKT_ESC_SETPOINT_10:
        return "PKT_ESC_SETPOINT_10";
    case PKT_ESC_SETPOINT_11:
        return "PKT_ESC_SETPOINT_11";
    case PKT_ESC_SETPOINT_12:
        return "PKT_ESC_SETPOINT_12";
    case PKT_ESC_SETPOINT_13:
        return "PKT_ESC_SETPOINT_13";
    case PKT_ESC_SETPOINT_14:
        return "PKT_ESC_SETPOINT_14";
    case PKT_ESC_SETPOINT_15:
        return "PKT_ESC_SETPOINT_15";
    case PKT_ESC_SETPOINT_16:
        return "PKT_ESC_SETPOINT_16";
    }
}


/*!
 * \brief Lookup label for 'ESCCommandPackets' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCCommandPackets_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case PKT_ESC_PWM_CMD:
        return "PKT_ESC_PWM_CMD";
    case PKT_ESC_RPM_CMD:
        return "PKT_ESC_RPM_CMD";
    case PKT_ESC_VOLT_CMD:
        return "PKT_ESC_VOLT_CMD";
    case PKT_ESC_DISABLE:
        return "PKT_ESC_DISABLE";
    case PKT_ESC_STANDBY:
        return "PKT_ESC_STANDBY";
    }
}


/*!
 * \brief Lookup label for 'ESCStatusPackets' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCStatusPackets_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case PKT_ESC_STATUS_A:
        return "PKT_ESC_STATUS_A";
    case PKT_ESC_STATUS_B:
        return "PKT_ESC_STATUS_B";
    case PKT_ESC_STATUS_C:
        return "PKT_ESC_STATUS_C";
    case PKT_ESC_STATUS_D:
        return "PKT_ESC_STATUS_D";
    case PKT_ESC_ACCELEROMETER:
        return "PKT_ESC_ACCELEROMETER";
    }
}


/*!
 * \brief Lookup label for 'ESCPackets' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCPackets_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case PKT_ESC_SYSTEM_CMD:
        return "PKT_ESC_SYSTEM_CMD";
    case PKT_ESC_SET_TITLE:
        return "PKT_ESC_SET_TITLE";
    case PKT_ESC_CONTROL_LOOP_DATA:
        return "PKT_ESC_CONTROL_LOOP_DATA";
    case PKT_ESC_HALL_SENSOR_INFO:
        return "PKT_ESC_HALL_SENSOR_INFO";
    case PKT_ESC_WARNINGS_ERRORS:
        return "PKT_ESC_WARNINGS_ERRORS";
    case PKT_ESC_MOTOR_FLAGS:
        return "PKT_ESC_MOTOR_FLAGS";
    case PKT_ESC_EVENT:
        return "PKT_ESC_EVENT";
    case PKT_ESC_SERIAL_NUMBER:
        return "PKT_ESC_SERIAL_NUMBER";
    case PKT_ESC_TITLE:
        return "PKT_ESC_TITLE";
    case PKT_ESC_FIRMWARE:
        return "PKT_ESC_FIRMWARE";
    case PKT_ESC_SYSTEM_INFO:
        return "PKT_ESC_SYSTEM_INFO";
    case PKT_ESC_TELEMETRY_SETTINGS:
        return "PKT_ESC_TELEMETRY_SETTINGS";
    case PKT_ESC_EEPROM:
        return "PKT_ESC_EEPROM";
    case PKT_ESC_EXTRA:
        return "PKT_ESC_EXTRA";
    case PKT_ESC_MOTOR_TEMP_SENSOR:
        return "PKT_ESC_MOTOR_TEMP_SENSOR";
    case PKT_ESC_COMMISSIONING:
        return "PKT_ESC_COMMISSIONING";
    case PKT_ESC_TELLTALES:
        return "PKT_ESC_TELLTALES";
    case PKT_ESC_GIT_HASH:
        return "PKT_ESC_GIT_HASH";
    case PKT_ESC_LEGACY_MOTOR_STATUS:
        return "PKT_ESC_LEGACY_MOTOR_STATUS";
    case PKT_ESC_LEGACY_MOTOR_SETTINGS:
        return "PKT_ESC_LEGACY_MOTOR_SETTINGS";
    case PKT_ESC_LEGACY_MOTOR_SETTINGS_2:
        return "PKT_ESC_LEGACY_MOTOR_SETTINGS_2";
    case PKT_ESC_LEGACY_MOTOR_FIRMWARE:
        return "PKT_ESC_LEGACY_MOTOR_FIRMWARE";
    case PKT_ESC_MOTOR_SETTINGS:
        return "PKT_ESC_MOTOR_SETTINGS";
    case PKT_ESC_MOTOR_STARTING:
        return "PKT_ESC_MOTOR_STARTING";
    case PKT_ESC_MOTOR_PARAMETERS:
        return "PKT_ESC_MOTOR_PARAMETERS";
    case PKT_ESC_MOTOR_HALL_CONFIG:
        return "PKT_ESC_MOTOR_HALL_CONFIG";
    case PKT_ESC_CONFIG:
        return "PKT_ESC_CONFIG";
    case PKT_ESC_WARNINGS:
        return "PKT_ESC_WARNINGS";
    case PKT_ESC_PROTECTION_LEVELS:
        return "PKT_ESC_PROTECTION_LEVELS";
    case PKT_ESC_PROTECTION_ACTIONS:
        return "PKT_ESC_PROTECTION_ACTIONS";
    case PKT_ESC_VOLT_LOOP_SETTINGS:
        return "PKT_ESC_VOLT_LOOP_SETTINGS";
    case PKT_ESC_RPM_LOOP_SETTINGS:
        return "PKT_ESC_RPM_LOOP_SETTINGS";
    case PKT_ESC_STARTING_SETTINGS:
        return "PKT_ESC_STARTING_SETTINGS";
    case PKT_ESC_CURRENT_CALIBRATION:
        return "PKT_ESC_CURRENT_CALIBRATION";
    case PKT_ESC_IO_TABLE_SETTINGS:
        return "PKT_ESC_IO_TABLE_SETTINGS";
    case PKT_ESC_IO_TABLE_ELEMENT:
        return "PKT_ESC_IO_TABLE_ELEMENT";
    case PKT_ESC_THROTTLE_CURVE:
        return "PKT_ESC_THROTTLE_CURVE";
    case PKT_ESC_PWM_INPUT_CALIBRATION:
        return "PKT_ESC_PWM_INPUT_CALIBRATION";
    case PKT_ESC_BULK_TRANSFER:
        return "PKT_ESC_BULK_TRANSFER";
    case PKT_ESC_DRONECAN_SETTINGS:
        return "PKT_ESC_DRONECAN_SETTINGS";
    }
}


/*!
 * \brief Lookup label for 'ESCSystemCommands' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* ESCSystemCommands_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case CMD_ESC_SET_NODE_ID:
        return "CMD_ESC_SET_NODE_ID";
    case CMD_ESC_SET_USER_ID_A:
        return "CMD_ESC_SET_USER_ID_A";
    case CMD_ESC_SET_USER_ID_B:
        return "CMD_ESC_SET_USER_ID_B";
    case CMD_ESC_TARE_CURRENT:
        return "CMD_ESC_TARE_CURRENT";
    case CMD_ESC_IDENTIFY:
        return "CMD_ESC_IDENTIFY";
    case CMD_ESC_SET_MOTOR_DIRECTION:
        return "CMD_ESC_SET_MOTOR_DIRECTION";
    case CMD_ESC_REQUEST_HF_DATA:
        return "CMD_ESC_REQUEST_HF_DATA";
    case CMD_ESC_CONFIGURE_IO_MAP:
        return "CMD_ESC_CONFIGURE_IO_MAP";
    case CMD_ESC_CONFIGURE_IO_ELEMENT:
        return "CMD_ESC_CONFIGURE_IO_ELEMENT";
    case CMD_ESC_RESET_SETTINGS:
        return "CMD_ESC_RESET_SETTINGS";
    case CMD_ESC_ENTER_DEBUG:
        return "CMD_ESC_ENTER_DEBUG";
    case CMD_ESC_EXIT_DEBUG:
        return "CMD_ESC_EXIT_DEBUG";
    case CMD_ESC_UNLOCK_SETTINGS:
        return "CMD_ESC_UNLOCK_SETTINGS";
    case CMD_ESC_LOCK_SETTINGS:
        return "CMD_ESC_LOCK_SETTINGS";
    case CMD_ESC_VALIDATE_SETTINGS:
        return "CMD_ESC_VALIDATE_SETTINGS";
    case CMD_ESC_RESET_MOTOR_RUN_TIME:
        return "CMD_ESC_RESET_MOTOR_RUN_TIME";
    case CMD_ESC_ENTER_BOOTLOADER:
        return "CMD_ESC_ENTER_BOOTLOADER";
    case CMD_ESC_RESET:
        return "CMD_ESC_RESET";
    }
}


/*!
 * \brief Lookup label for 'CANProtocols' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* CANProtocols_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case CAN_PROTOCOL_PICCOLO:
        return "CAN_PROTOCOL_PICCOLO";
    case CAN_PROTOCOL_DRONECAN:
        return "CAN_PROTOCOL_DRONECAN";
    case CAN_PROTOCOL_NONE:
        return "CAN_PROTOCOL_NONE";
    }
}


/*!
 * \brief Lookup label for 'CANBaudRates' enum entry
 * 
 * \param value is the integer value of the enum entry
 * \return string label of the given entry
 */
const char* CANBaudRates_EnumLabel(int value)
{
    switch (value)
    {
    default:
        return "";
    case CAN_BAUD_RATES_INVALID:
        return "CAN_BAUD_RATES_INVALID";
    case CAN_BAUD_RATES_1000K:
        return "CAN_BAUD_RATES_1000K";
    case CAN_BAUD_RATES_500K:
        return "CAN_BAUD_RATES_500K";
    case CAN_BAUD_RATES_250K:
        return "CAN_BAUD_RATES_250K";
    case CAN_BAUD_RATES_125K:
        return "CAN_BAUD_RATES_125K";
    case CAN_BAUD_RATES_100K:
        return "CAN_BAUD_RATES_100K";
    case CAN_BAUD_RATES_50K:
        return "CAN_BAUD_RATES_50K";
    }
}

// end of ESCVelocityProtocol.c
