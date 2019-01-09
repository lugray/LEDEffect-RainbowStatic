/* This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Kaleidoscope-LEDControl.h"

namespace kaleidoscope {
namespace plugin {

class LEDRainbowStaticEffect : public LEDMode {
 public:
  LEDRainbowStaticEffect(void) {}

  void end_hue(uint16_t);
  uint16_t end_hue(void) {
    return rainbow_end_hue;
  }
  void start_hue(uint16_t);
  uint16_t start_hue(void) {
    return rainbow_start_hue;
  }
  void brightness(byte);
  byte brightness(void) {
    return rainbow_value;
  }
  void onActivate(void) final;
  void update(void) final;

 private:
  uint16_t rainbow_start_hue = 0;  //  stores 0 to 614
  uint16_t rainbow_end_hue = 256;  //  stores 0 to 614

  byte rainbow_saturation = 255;
  byte rainbow_value = 50;
  uint32_t activate_millis = 0;
  uint16_t ramp_time = 1000;
};
}
}

extern kaleidoscope::plugin::LEDRainbowStaticEffect LEDRainbowStaticEffect;
