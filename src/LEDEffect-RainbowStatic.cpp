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

#include "LEDEffect-RainbowStatic.h"

namespace kaleidoscope {
namespace plugin {

void LEDRainbowStaticEffect::onActivate(void) {
  for (int8_t i = 0; i < LED_COUNT; i++) {
    uint16_t key_hue = rainbow_start_hue + (rainbow_end_hue * 4 / LED_COUNT) * (i / 4);
    if (key_hue >= 255)          {
      key_hue -= 255;
    }
    cRGB rainbow = hsvToRgb(key_hue, rainbow_saturation, rainbow_value);
    ::LEDControl.setCrgbAt(i, rainbow);
  }
}

void LEDRainbowStaticEffect::brightness(byte brightness) {
  rainbow_value = brightness;
}

void LEDRainbowStaticEffect::start_hue(uint16_t hue) {
  rainbow_start_hue = hue;
}

void LEDRainbowStaticEffect::end_hue(uint16_t hue) {
  rainbow_end_hue = hue;
}

}
}

kaleidoscope::plugin::LEDRainbowStaticEffect LEDRainbowStaticEffect;
