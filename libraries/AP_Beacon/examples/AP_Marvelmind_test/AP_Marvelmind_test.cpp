/*
  simple test of UART interfaces
 */

#include <AP_HAL/AP_HAL.h>
#include <AP_Beacon/AP_Beacon_Marvelmind.h>
#include <AP_Beacon/AP_Beacon.h>
#include <AP_SerialManager/AP_SerialManager.h>
#include <stdio.h>

void setup();
void loop();
void set_object_value_and_report(const void *object_pointer,
                      const struct AP_Param::GroupInfo *group_info,
                      const char *name, float value);

const AP_HAL::HAL& hal = AP_HAL::get_HAL();
static AP_SerialManager serial_manager;
#if AP_BEACON_ENABLED
AP_Beacon beacon;
#endif

// try to set the object value but provide diagnostic if it failed
void set_object_value_and_report(const void *object_pointer,
                      const struct AP_Param::GroupInfo *group_info,
                      const char *name, float value)
{
    if (!AP_Param::set_object_value(object_pointer, group_info, name, value)) {
        printf("WARNING: AP_Param::set object value \"%s::%s\" Failed.\n",
                            group_info->name, name);
    }
}

void setup(void)
{
#if AP_BEACON_ENABLED
    set_object_value_and_report(&beacon, beacon.var_info, "_TYPE", 2.0f);
    set_object_value_and_report(&serial_manager, serial_manager.var_info, "0_PROTOCOL", 13.0f);
#endif
    serial_manager.init();
#if AP_BEACON_ENABLED
    beacon.init();
#endif
}

void loop(void)
{
#if AP_BEACON_ENABLED
    static int count = 0;
    beacon.update();
    Vector3f pos;
    float accuracy = 0.0f;
    beacon.get_vehicle_position_ned(pos, accuracy);
    if (pos.x > 0.001f) {
        printf("%f %f %f\n", static_cast<double>(pos.x), static_cast<double>(pos.y), static_cast<double>(pos.z));
        count++;
    }
    hal.scheduler->delay(1000);
    if (count == 3)
        exit(0);
#else
    printf("Beacon not available\n");
    hal.scheduler->delay(1000);
#endif
}

AP_HAL_MAIN();
