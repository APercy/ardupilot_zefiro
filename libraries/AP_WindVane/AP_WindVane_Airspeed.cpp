/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AP_WindVane_config.h"

#if AP_WINDVANE_AIRSPEED_ENABLED

#include "AP_WindVane_Airspeed.h"

void AP_WindVane_Airspeed::update_speed()
{
    const AP_Airspeed* airspeed = AP_Airspeed::get_singleton();
    if (airspeed != nullptr) {
        _frontend._speed_apparent_raw = airspeed->get_raw_airspeed();
    }
}

#endif  // AP_WINDVANE_AIRSPEED_ENABLED
