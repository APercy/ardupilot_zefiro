#pragma once

#include <AP_HAL/AP_HAL_Boards.h>

#ifndef AP_RELAY_ENABLED
#define AP_RELAY_ENABLED 1
#endif

#define AP_RELAY_DRONECAN_ENABLED AP_RELAY_ENABLED && HAL_ENABLE_DRONECAN_DRIVERS && !defined(HAL_BUILD_AP_PERIPH)
