/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#tapping-term
#define TAPPING_TERM_PER_KEY

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
#define COMBO_COUNT 1

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
// If defined, the RGB lighting will be switched off when the host goes to sleep
#define RGBLIGHT_SLEEP
// If defined, disables the ability to control RGB Light from the keycodes. You must use code functions to control the feature
#define RGBLIGHT_SPLIT
// Enable RGB lighting upon clearing the EEPROM
#define RGBLIGHT_DEFAULT_ON false
