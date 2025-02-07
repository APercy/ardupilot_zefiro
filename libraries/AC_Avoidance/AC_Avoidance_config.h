#pragma once

#include <AP_HAL/AP_HAL_Boards.h>
#include <AC_Fence/AC_Fence_config.h>

#ifndef AP_AVOIDANCE_ENABLED
#define AP_AVOIDANCE_ENABLED AP_FENCE_ENABLED
#endif

#ifndef AP_OAPATHPLANNER_ENABLED
#define AP_OAPATHPLANNER_ENABLED AP_FENCE_ENABLED
#endif

#ifndef AP_OAPATHPLANNER_BACKEND_DEFAULT_ENABLED
#define AP_OAPATHPLANNER_BACKEND_DEFAULT_ENABLED AP_OAPATHPLANNER_ENABLED
#endif

#ifndef AP_OAPATHPLANNER_BENDYRULER_ENABLED
#define AP_OAPATHPLANNER_BENDYRULER_ENABLED AP_OAPATHPLANNER_BACKEND_DEFAULT_ENABLED
#endif

#ifndef AP_OAPATHPLANNER_DIJKSTRA_ENABLED
#define AP_OAPATHPLANNER_DIJKSTRA_ENABLED AP_OAPATHPLANNER_BACKEND_DEFAULT_ENABLED
#endif



#ifndef AP_OADATABASE_ENABLED
#define AP_OADATABASE_ENABLED AP_OAPATHPLANNER_ENABLED
#endif
