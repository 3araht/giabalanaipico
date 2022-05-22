/*
Copyright 2020 3araht

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0xF4C0
#define DEVICE_VER   0x0001
#define MANUFACTURER 3araht
#define PRODUCT      giabalanaipico

/* key matrix size */
#define MATRIX_ROWS 20
#define MATRIX_COLS 8

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { 4, 5, 7, 9, 10, 11, 12, 13, 14, 15 }
#define MATRIX_COL_PINS { 22, 21, 20, 19, 18, 17, 16, 26}
/* pin 26 above is a dummy for cw and ccw for REMAPping encoder. */

#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Handedness by Pin */
/* pull-up: left side,   pull-down: right side */
#define SPLIT_HAND_PIN 28

/* test matrix scan speed */
// #define DEBUG_MATRIX_SCAN_RATE

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN 0
#define SELECT_SOFT_SERIAL_SPEED 1
/*Sets the protocol speed when using serial communication*/
//Speeds:
//0: about 189kbps (Experimental only)
//1: about 137kbps (default)
//2: about 75kbps
//3: about 39kbps
//4: about 26kbps
//5: about 20kbps

// Right side has to be the master since 1, LED data is output from right side, and 2, Audio pin is prepared on right side as a reserve.
#define MASTER_RIGHT

// 2022/03/28 added. This might solve the "no left side communication via TRRS" issue.
// #define SPLIT_USB_DETECT
// SPLIT_USB_DETECT was not necessary since it is "Enabled by default on ChibiOS/ARM."

//#define BACKLIGHT_PIN B7
//#define BACKLIGHT_LEVELS 3
//#define BACKLIGHT_BREATHING

/* ws2812 RGB LED */
#define RGB_DI_PIN 6

#ifdef RGB_MATRIX_ENABLE

/* ws2812 RGB MATRIX */
#    define DRIVER_LED_TOTAL 123
#    define RGB_MATRIX_KEYPRESSES  // reacts to keypresses

//  for all fingers used at once.
#    define LED_HITS_TO_REMEMBER 10

#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50

// the above brighness setting has no effect on rgb_matrix_set_color().
// Use darker colors instead.
/*              RGB darker COLORS             */
#define RGB_DARKWHITE 0x66, 0x66, 0x66
#define RGB_DARKRED 0x66, 0x0, 0x0
#define RGB_DARKCORAL 0x66, 0x31, 0x1E
#define RGB_DARKORANGE 0x66, 0x33, 0x0
#define RGB_DARKGOLDENROD 0x56, 0x42, 0xD
#define RGB_DARKGOLD 0x66, 0x56, 0x0
#define RGB_DARKYELLOW 0x66, 0x66, 0x0
#define RGB_DARKCHARTREUSE 0x33, 0x66, 0x0
#define RGB_DARKGREEN 0x0, 0x66, 0x0
#define RGB_DARKSPRINGGREEN 0x0, 0x66, 0x33
#define RGB_DARKTURQUOISE 0x1C, 0x2C, 0x2A
#define RGB_DARKTEAL 0x0, 0x33, 0x33
#define RGB_DARKCYAN 0x0, 0x66, 0x66
#define RGB_DARKAZURE 0x3D, 0x62, 0x66
#define RGB_DARKBLUE 0x0, 0x0, 0x66
#define RGB_DARKPURPLE 0x30, 0x0, 0x66
#define RGB_DARKMAGENTA 0x66, 0x0, 0x66
#define RGB_DARKPINK 0x66, 0x33, 0x4C

//  https://docs.qmk.fm/#/feature_rgb_matrix
//  Enable suspend mode.
// #    define RGB_DISABLE_WHEN_USB_SUSPENDED true

// #define DISABLE_RGB_MATRIX_SOLID_COLOR
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #    define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #    define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #    define DISABLE_RGB_MATRIX_BREATHING
// #    define DISABLE_RGB_MATRIX_BAND_SAT
// #define DISABLE_RGB_MATRIX_BAND_VAL
// #    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #    define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #    define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define DISABLE_RGB_MATRIX_CYCLE_ALL
// #    define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// // #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #    define DISABLE_RGB_MATRIX_DUAL_BEACON
// #    define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #    define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
// // #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
// #    define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #    define DISABLE_RGB_MATRIX_RAINDROPS
// #    define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define DISABLE_RGB_MATRIX_HUE_BREATHING
// #define DISABLE_RGB_MATRIX_HUE_PENDULUM
// #define DISABLE_RGB_MATRIX_HUE_WAVE
// #    define DISABLE_RGB_MATRIX_TYPING_HEATMAP
// #    define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #    define DISABLE_RGB_MATRIX_SPLASH
// #    define DISABLE_RGB_MATRIX_MULTISPLASH
// #    define DISABLE_RGB_MATRIX_SOLID_SPLASH
// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

// #define DISABLE_RGB_MATRIX_SOLID_COLOR
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_BREATHING
// #define DISABLE_RGB_MATRIX_BAND_SAT  // white background ver. of _BAND_VAL
// #define DISABLE_RGB_MATRIX_BAND_VAL
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define DISABLE_RGB_MATRIX_CYCLE_ALL
// #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define DISABLE_RGB_MATRIX_DUAL_BEACON
// #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
// #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define DISABLE_RGB_MATRIX_RAINDROPS
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS  //White ver of above.
// #define DISABLE_RGB_MATRIX_HUE_BREATHING
// #define DISABLE_RGB_MATRIX_HUE_PENDULUM
// #define DISABLE_RGB_MATRIX_HUE_WAVE
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
// #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define DISABLE_RGB_MATRIX_SPLASH
// #define DISABLE_RGB_MATRIX_MULTISPLASH
// #define DISABLE_RGB_MATRIX_SOLID_SPLASH
// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif  // RGB_MATRIX_ENABLE

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

// /* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
// /* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

/* Audio */
#ifdef AUDIO_ENABLE
#    define AUDIO_PIN 8  // use EX1 = PB5 = PIN9 as Audio output
// #define DAC_SAMPLE_MAX 32768U
#    define DAC_SAMPLE_MAX 65535U
// #define AUDIO_CLICKY
#    define NO_MUSIC_MODE
// #define STARTUP_SONG SONG(FANTASIE_IMPROMPTU)
// #define STARTUP_SONG SONG(NOCTURNE_OP_9_NO_1)
// #define STARTUP_SONG SONG(USSR_ANTHEM)
// #define STARTUP_SONG SONG(CAMPANELLA)
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#ifdef MIDI_ENABLE
#    define MIDI_ADVANCED
// Initial velocity value (avoid using 127 since it is used as a special number in some sound sources.)
#    define MIDI_INITIAL_VELOCITY 117
#endif  //  MIDI_ENABLE

/*
 * Encoder options
 */
#ifdef ENCODER_ENABLE
#   define ENCODERS_PAD_A { 2 }  // dummy
#   define ENCODERS_PAD_B { 3 }  // dummy
#   define ENCODERS_PAD_A_RIGHT { 2 }
#   define ENCODERS_PAD_B_RIGHT { 3 }
#   define ENCODER_RESOLUTION 4
#   define TAP_CODE_DELAY 10
// Enncoder settings for VIA support
#   define ENCODERS 2  // the first one is a dummy, there is only one on the right hand side.
#   define ENCODERS_CW_KEY  { {7, 17}, {7, 16} }
#   define ENCODERS_CCW_KEY { {7, 18}, {7, 15} }
#endif  // ENCODER_ENABLE

/* 2021/01/22 added to shrink firmware size */
// NO_ACTION_TAPPING -1964 bytes, however, this disables Layer mods...
// #define NO_ACTION_TAPPING
// NO_ACTION_ONESHOT -388 bytes
#define NO_ACTION_ONESHOT

/* via layer setting */
/* default: 4 */
#define DYNAMIC_KEYMAP_LAYER_COUNT 12
