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
#pragma once

#include "AP_OpticalFlow_config.h"

#if AP_OPTICALFLOW_ONBOARD_ENABLED

#include <AP_OpticalFlow/AP_OpticalFlow_Backend.h>

#include "AP_OpticalFlow.h"

class AP_OpticalFlow_Onboard : public OpticalFlow_backend
{
public:

    using OpticalFlow_backend::OpticalFlow_backend;

    void init(void) override;
    void update(void) override;
private:
    uint32_t _last_read_ms;
};

#endif  // AP_OPTICALFLOW_ONBOARD_ENABLED
