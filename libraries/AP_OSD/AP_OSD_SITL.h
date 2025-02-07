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
 */
#pragma once

#ifdef WITH_SITL_OSD

#include <AP_OSD/AP_OSD_Backend.h>

#ifdef HAVE_SFML_GRAPHICS_H
#include <SFML/Graphics.h>
#else
#include <SFML/Graphics.hpp>
#endif

class AP_OSD_SITL : public AP_OSD_Backend
{

public:
    static AP_OSD_Backend *probe(AP_OSD &osd);

    //draw given text to framebuffer
    void write(uint8_t x, uint8_t y, const char* text) override;

    //initialize display port and underlying hardware
    bool init() override;

    //flush framebuffer to screen
    void flush() override;

    //clear framebuffer
    void clear() override;

    bool is_compatible_with_backend_type(AP_OSD::osd_types type) const override {
        switch(type) {
        case AP_OSD::osd_types::OSD_MAX7456:
        case AP_OSD::osd_types::OSD_SITL:
            return false;
        case AP_OSD::osd_types::OSD_NONE:
        case AP_OSD::osd_types::OSD_TXONLY:
        case AP_OSD::osd_types::OSD_MSP:
        case AP_OSD::osd_types::OSD_MSP_DISPLAYPORT:
            return true;
        }
        return false;
    }

    AP_OSD::osd_types get_backend_type() const override {
        return AP_OSD::osd_types::OSD_SITL;
    }
private:
    //constructor
    AP_OSD_SITL(AP_OSD &osd);

    sf::RenderWindow *w;

    sf::Texture font[256];
    uint8_t last_font;

    // setup to match MAX7456 layout
    static const uint8_t char_width = 12;
    static const uint8_t char_height = 18;
    uint8_t video_lines;
    uint8_t video_cols;
    static const uint8_t char_spacing = 0;

    // scaling factor to make it easier to read
    static const uint8_t char_scale = 2;

    // get a byte from a buffer
    uint8_t &getbuffer(uint8_t *buf, uint8_t y, uint8_t x) const {
        return buf[y*uint32_t(video_cols) + x];
    }

    uint8_t *buffer;

    void update_thread();
    static void *update_thread_start(void *obj);
    void load_font();

    pthread_t thread;
    HAL_Semaphore mutex;
    uint32_t counter;
    uint32_t last_counter;
};

#endif // WITH_SITL_OSD
