#pragma once

#include <AP_HAL/AP_HAL_Boards.h>

// note boards.py sets this, so the default value in here doesn't
// really matter:
//#ifndef AP_CUSTOMCONTROL_ENABLED
//#define AP_CUSTOMCONTROL_ENABLED 0
//#endif

#ifndef AP_CUSTOMCONTROL_BACKEND_DEFAULT_ENABLED
#define AP_CUSTOMCONTROL_BACKEND_DEFAULT_ENABLED AP_CUSTOMCONTROL_ENABLED
#endif

#ifndef AP_CUSTOMCONTROL_EMPTY_ENABLED
#define AP_CUSTOMCONTROL_EMPTY_ENABLED AP_CUSTOMCONTROL_BACKEND_DEFAULT_ENABLED
#endif

#ifndef AP_CUSTOMCONTROL_PID_ENABLED
#define AP_CUSTOMCONTROL_PID_ENABLED AP_CUSTOMCONTROL_BACKEND_DEFAULT_ENABLED
#endif
