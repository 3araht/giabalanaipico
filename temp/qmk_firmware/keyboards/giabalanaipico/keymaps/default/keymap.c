/* Copyright 2022 3araht
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "version.h"

// Alias layout macros that expand groups of keys.
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define DF_CBAS  DF(_C_SYSTEM_BASE)
#define DF_QWER  DF(_QWERTY)
// Long press: go to _FN layer, tap: MUTE
#define FN_MUTE LT(_FN, KC_MUTE)

#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________COLEMAK_L1________________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________ KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________ KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________ KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________NUMBER_L__________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_R__________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC__L___________________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC__R___________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

// Used to set octave to QK_MIDI_OCTAVE_0
extern midi_config_t midi_config;
uint8_t midi_bass_ch = 0, midi_chord_ch = 0;  // By default, all use the same channel.

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _C_SYSTEM_BASE,  //  MIDI C-system
    _QWERTY,         //  just in case
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {

    // MIDI Chord Keycodes - Root notes
    MY_CHORD_MIN = SAFE_RANGE,

    MI_CH_Cr = MY_CHORD_MIN,
    MI_CH_Csr,
    MI_CH_Dbr = MI_CH_Csr,
    MI_CH_Dr,
    MI_CH_Dsr,
    MI_CH_Ebr = MI_CH_Dsr,
    MI_CH_Er,
    MI_CH_Fr,
    MI_CH_Fsr,
    MI_CH_Gbr = MI_CH_Fsr,
    MI_CH_Gr,
    MI_CH_Gsr,
    MI_CH_Abr = MI_CH_Gsr,
    MI_CH_Ar,
    MI_CH_Asr,
    MI_CH_Bbr = MI_CH_Asr,
    MI_CH_Br,

    // MIDI Chord Keycodes - Major

    MI_CH_C,
    MI_CH_Cs,
    MI_CH_Db = MI_CH_Cs,
    MI_CH_D,
    MI_CH_Ds,
    MI_CH_Eb = MI_CH_Ds,
    MI_CH_E,
    MI_CH_F,
    MI_CH_Fs,
    MI_CH_Gb = MI_CH_Fs,
    MI_CH_G,
    MI_CH_Gs,
    MI_CH_Ab = MI_CH_Gs,
    MI_CH_A,
    MI_CH_As,
    MI_CH_Bb = MI_CH_As,
    MI_CH_B,

    // MIDI Chord Keycodes Minor

    MI_CH_Cm,
    MI_CH_Csm,
    MI_CH_Dbm = MI_CH_Csm,
    MI_CH_Dm,
    MI_CH_Dsm,
    MI_CH_Ebm = MI_CH_Dsm,
    MI_CH_Em,
    MI_CH_Fm,
    MI_CH_Fsm,
    MI_CH_Gbm = MI_CH_Fsm,
    MI_CH_Gm,
    MI_CH_Gsm,
    MI_CH_Abm = MI_CH_Gsm,
    MI_CH_Am,
    MI_CH_Asm,
    MI_CH_Bbm = MI_CH_Asm,
    MI_CH_Bm,

    //MIDI Chord Keycodes Dominant Seventh

    MI_CH_CDom7,
    MI_CH_CsDom7,
    MI_CH_DbDom7 = MI_CH_CsDom7,
    MI_CH_DDom7,
    MI_CH_DsDom7,
    MI_CH_EbDom7 = MI_CH_DsDom7,
    MI_CH_EDom7,
    MI_CH_FDom7,
    MI_CH_FsDom7,
    MI_CH_GbDom7 = MI_CH_FsDom7,
    MI_CH_GDom7,
    MI_CH_GsDom7,
    MI_CH_AbDom7 = MI_CH_GsDom7,
    MI_CH_ADom7,
    MI_CH_AsDom7,
    MI_CH_BbDom7 = MI_CH_AsDom7,
    MI_CH_BDom7,

    // MIDI Chord Keycodes Diminished Seventh

    MI_CH_CDim7,
    MI_CH_CsDim7,
    MI_CH_DbDim7 = MI_CH_CsDim7,
    MI_CH_DDim7,
    MI_CH_DsDim7,
    MI_CH_EbDim7 = MI_CH_DsDim7,
    MI_CH_EDim7,
    MI_CH_FDim7,
    MI_CH_FsDim7,
    MI_CH_GbDim7 = MI_CH_FsDim7,
    MI_CH_GDim7,
    MI_CH_GsDim7,
    MI_CH_AbDim7 = MI_CH_GsDim7,
    MI_CH_ADim7,
    MI_CH_AsDim7,
    MI_CH_BbDim7 = MI_CH_AsDim7,
    MI_CH_BDim7,

    MY_CHORD_MAX = MI_CH_BDim7,

    VERSION
};

#define MY_CHORD_COUNT (MY_CHORD_MAX - MY_CHORD_MIN + 1)
static uint8_t chord_status[MY_CHORD_COUNT];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* C-system Base */
  [_C_SYSTEM_BASE] = LAYOUT(
    DF_CBAS, MI_VELU,  MI_CH_Dbr,    MI_CH_Abr,    MI_CH_Ebr,    MI_CH_Bbr,    MI_CH_Fr,    MI_CH_Cr,    MI_CH_Gr,    MI_CH_Dr,    MI_CH_Ar,    MI_CH_Er,    MI_CH_Br,    MI_CH_Fsr,
      MI_BNDU, MI_VELD, MI_CH_Db,     MI_CH_Ab,     MI_CH_Eb,     MI_CH_Bb,     MI_CH_F,     MI_CH_C,     MI_CH_G,     MI_CH_D,     MI_CH_A,     MI_CH_E,     MI_CH_B,     MI_CH_Fs,
        MI_BNDD, DF_QWER, MI_CH_Dbm,    MI_CH_Abm,    MI_CH_Ebm,    MI_CH_Bbm,    MI_CH_Fm,    MI_CH_Cm,    MI_CH_Gm,    MI_CH_Dm,    MI_CH_Am,    MI_CH_Em,    MI_CH_Bm,    MI_CH_Fsm,
          MI_SUST,  KC_VOLU, MI_CH_DbDom7, MI_CH_AbDom7, MI_CH_EbDom7, MI_CH_BbDom7, MI_CH_FDom7, MI_CH_CDom7, MI_CH_GDom7, MI_CH_DDom7, MI_CH_ADom7, MI_CH_EDom7, MI_CH_BDom7, MI_CH_FsDom7,
            FN_MUTE, KC_VOLD, MI_CH_DbDim7, MI_CH_AbDim7, MI_CH_EbDim7, MI_CH_BbDim7, MI_CH_FDim7, MI_CH_CDim7, MI_CH_GDim7, MI_CH_DDim7, MI_CH_ADim7, MI_CH_EDim7, MI_CH_BDim7, MI_CH_FsDim7,

              MI_G2,  MI_Bb2, MI_Db3, MI_E3,  MI_G3,  MI_Bb3, MI_Db4, MI_E4,  MI_G4,  MI_Bb4, MI_Db5, MI_E5,             MI_OCTD,  MI_OCTU,
            MI_Fs2, MI_A2,  MI_C3,  MI_Eb3, MI_Fs3, MI_A3,  MI_C4,  MI_Eb4, MI_Fs4, MI_A4,  MI_C5,  MI_Eb5, MI_Fs5,               MI_BNDU,
              MI_Ab2, MI_B2,  MI_D3,  MI_F3,  MI_Ab3, MI_B3,  MI_D4,  MI_F4,  MI_Ab4, MI_B4,  MI_D5,  MI_F5,    FN_MUTE,
            MI_G2,  MI_Bb2, MI_Db3, MI_E3,  MI_G3,  MI_Bb3, MI_Db4, MI_E4,  MI_G4,  MI_Bb4, MI_Db5, MI_E5,  MI_G5,                MI_BNDD,
    MI_SUST,   MI_A2,  MI_C3,  MI_Eb3, MI_Fs3, MI_A3,  MI_C4,  MI_Eb4, MI_Fs4, MI_A4,  MI_C5,  MI_Eb5, MI_Fs5,            MI_TRSD, MI_TRSU
  ),

  /* QWERTY */
  [_QWERTY] = LAYOUT_wrapper(
    _______, _______, QK_GESC, _________________NUMBER_L__________________, _________________NUMBER_R__________________, KC_BSPC,
      _______, _______, KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_DEL,
        _______, _______, KC_CAPS, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_ENT,
          _______, _______, KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT,
            _______, _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LNG2, KC_SPC,  KC_SPC,  KC_SPC, KC_SPC, KC_LNG1, KC_RALT,  KC_RGUI, KC_RCTL,

               QK_GESC, _________________NUMBER_L__________________, _________________NUMBER_R__________________, KC_BSPC,            _______, _______,
             KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_MINS, KC_DEL,               _______,
               KC_LCTL, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_ENT,    _______,
             KC_CAPS, KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT,              _______,
    _______,   KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, KC_LNG2, KC_SPC, KC_SPC, KC_LNG1,  KC_APP,  KC_RALT, KC_RGUI,  KC_RCTL,           _______, _______
  ),


  /* Fn */
  [_FN] = LAYOUT(
    _______, _______, DF_CBAS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, DF_QWER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

               DF_CBAS,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, MI_VELD, MI_VELU, XXXXXXX,            _______, _______,
             XXXXXXX, DF_QWER,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, MI_TRSD, MI_TRSU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                _______,
               MI_OCN2, MI_OCN1, MI_OC0, MI_OC1, MI_OC2, XXXXXXX,  XXXXXXX, MI_OCTD, MI_OCTU, XXXXXXX, VERSION, EE_CLR,    _______,
             DF_CBAS, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, MI_VELD, MI_VELU, XXXXXXX, XXXXXXX,                _______,
    _______,   DF_QWER,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MI_TRSD, MI_TRSU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            _______, _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_C_SYSTEM_BASE]        = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_QWERTY]               = { ENCODER_CCW_CW(_______, _______) },
    [_FN]                   = { ENCODER_CCW_CW(_______, _______) }
};
#endif

void keyboard_post_init_user(void) {
    //  Set otave to QK_MIDI_OCTAVE_0
    midi_config.octave = QK_MIDI_OCTAVE_0 - MIDI_OCTAVE_MIN;

    // avoid using 127 since it is used as a special number in some sound sources.
    midi_config.velocity = MIDI_INITIAL_VELOCITY;

    for (uint8_t i = 0; i < MY_CHORD_COUNT; i++) {
        chord_status[i] = MIDI_INVALID_NOTE;
    }

    default_layer_set(1UL << _C_SYSTEM_BASE);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t root_note = MIDI_INVALID_NOTE;  // Starting value for the root note of each chord

    uint8_t chord        = keycode - MY_CHORD_MIN;

    switch (keycode) {
        case VERSION: // Output firmware info.
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " @ " QMK_VERSION " | " QMK_BUILDDATE);
            }
            break;

        // MIDI Chord Keycodes, on the left side.
        case MI_CH_Cr ... MI_CH_Br:  // Root Notes
            root_note = keycode - MI_CH_Cr + MI_C1;
            my_process_midi4Bass(midi_bass_ch, record, chord_status, chord, root_note, false);
            break;

        case MI_CH_C ... MI_CH_B:  // Major Chords
            root_note = keycode - MI_CH_C + MI_C2;
            // Root, Major Third, and Fifth Notes
            my_process_midi4TriadChords(midi_chord_ch, record, chord_status, chord, root_note, 0, 4, 7);
            break;

        case MI_CH_Cm ... MI_CH_Bm:  // Minor Chord
            root_note = keycode - MI_CH_Cm + MI_C2;
            // Root, Minor Third, and Fifth Notes
            my_process_midi4TriadChords(midi_chord_ch, record, chord_status, chord, root_note, 0, 3, 7);
            break;

        case MI_CH_CDom7 ... MI_CH_BDom7:  // Dominant 7th Chord
            root_note = keycode - MI_CH_CDom7 + MI_C2;
            // Major Third, Major Fifth, and Minor Seventh Notes
            my_process_midi4TriadChords(midi_chord_ch, record, chord_status, chord, root_note, 4, 7, 10);
            break;

        case MI_CH_CDim7 ... MI_CH_BDim7:                // Diminished 7th Chord
            root_note = keycode - MI_CH_CDim7 + MI_C2;
            // Root, Minor Third, and Diminished 5th Note
            my_process_midi4TriadChords(midi_chord_ch, record, chord_status, chord, root_note, 0, 3, 6);
            break;
    }
    return true;
}
