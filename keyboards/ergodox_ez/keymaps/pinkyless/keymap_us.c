#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _B1 0 // Base layer
#define _B2 1 // Base layer
#define _HL 2 // HHKB fn like layer

// Layer
#define MO_HHKB  MO(_HL)     // HHKB Layer

// SandS
#define K_SANDC LCTL_T(KC_SPC)      // Space and Ctrl
#define K_RANDS LSFT_T(KC_ENT)      // Return and Shift

// macOS Eisuu/Kana
#define K_MEISU KC_LANG2
#define K_MKANA KC_LANG1

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  PDF1,
  PDF2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* US layer
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------| BSPC |      |      |      |      |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |   !  |   @  |   #  |   $  |   %  |   ^  | |  &   |  *   |  (   |  )   |  _   |  +   |   |    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |   &  | |  ^   |      |      |      |      |      |   ~    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------|      |      |      |      |  :   |   "    |
 * |--------+------+------+------+------+------|   {  | |  }   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |  <   |  >   |  ?   |   ~    |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  | |  7   |  8   |  9   |  0   |  -   |  =   |   \    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |   7  | |  6   |  Y   |  U   |  I   |  O   |  P   |   `    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |   Ctl  |   A  |   S  |   D  |   F  |   G  |------| |------|  H   |  J   |  K   |  L   |  ;   |   '    |
 * |--------+------+------+------+------+------|   [  | |  ]   |------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |      | |      |  N   |  M   |  ,   |  .   |  /   |   `    |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   | LAlt | LGui |      |      | EISU |                             | KANA | RGui | RAlt | RSft | HHKB |
 *   '----------------------------------'                             '----------------------------------'
 *                                    .---------------. .---------------.
 *                                    |  Gui  |  Alt  | |  INS  | SLCK  |
 *                            .-------+-------+-------| |-------+-------+-------.
 *                            |    [C]|       | PRSCR | | BREAK |       |    [S]|
 *                            | Space | Space |-------| |-------| Enter | Enter |
 *                            |       |       |  DEL  | | BSPC  |       |       |
 *                            '-----------------------' '-----------------------'
 */
[_B1] = LAYOUT_ergodox(
      // left hand
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,
      KC_LALT, KC_LGUI, KC_NO,   KC_NO,   K_MEISU,
                                                   KC_RGUI, KC_RALT,
                                                            KC_PSCR,
                                          K_SANDC, KC_SPC,  KC_DEL,
      // right hand
      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
      KC_6,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                        K_MKANA, KC_RGUI, KC_RALT, KC_RSFT, MO_HHKB,
      KC_INS,  KC_SLCK,
      KC_BRK,
      KC_BSPC, KC_ENT,  K_RANDS
),

/* US layer
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------| BSPC |      |      |      |      |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |   !  |   @  |   #  |   $  |   %  |   ^  | |  &   |  *   |  (   |  )   |  _   |  +   |   |    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |   &  | |  ^   |      |      |      |      |      |   ~    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------|      |      |      |      |  :   |   "    |
 * |--------+------+------+------+------+------|   {  | |  }   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |  <   |  >   |  ?   |   ~    |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  | |  7   |  8   |  9   |  0   |  -   |  =   |   \    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |   7  | |  6   |  Y   |  U   |  I   |  O   |  P   |   `    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |   Ctl  |   A  |   S  |   D  |   F  |   G  |------| |------|  H   |  J   |  K   |  L   |  ;   |   '    |
 * |--------+------+------+------+------+------|   [  | |  ]   |------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |      | |      |  N   |  M   |  ,   |  .   |  /   |   `    |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   | LAlt | LGui |      |      | EISU |                             | KANA | RGui | RAlt | RSft | HHKB |
 *   '----------------------------------'                             '----------------------------------'
 *                                    .---------------. .---------------.
 *                                    |  Gui  |  Alt  | |  INS  | SLCK  |
 *                            .-------+-------+-------| |-------+-------+-------.
 *                            |       |       | PRSCR | | BREAK |       |       |
 *                            | Space |  Ctrl |-------| |-------| Shift | Enter |
 *                            |       |       |  DEL  | | BSPC  |       |       |
 *                            '-----------------------' '-----------------------'
 */
[_B2] = LAYOUT_ergodox(
      // left hand
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,
      KC_LALT, KC_LGUI, KC_NO,   KC_NO,   K_MEISU,
                                                   KC_RGUI, KC_RALT,
                                                            KC_PSCR,
                                          KC_SPC,  KC_LCTL, KC_DEL,
      // right hand
      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
      KC_6,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                        K_MKANA, KC_RGUI, KC_RALT, KC_RSFT, MO_HHKB,
      KC_INS,  KC_SLCK,
      KC_BRK,
      KC_BSPC, KC_RSFT, KC_ENT
),

/* HHKB layer
 * .--------------------------------------------------. .--------------------------------------------------.
 * |  Power |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |  Caps  |      |      |      |      |      | DEBG | | REST |  x   |  x   |  x   |  x   |  INS |  DEL   |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        | VOLD | VOLU | MUTE | EJCT |      |------| |------|  x   | PSCR | SLCK | BRK  |  ↑   |  BS    |
 * |--------+------+------+------+------+------| VRSN | | EPRM |------+------+------+------+------+--------|
 * |        | MPRV | MNXT | MSTP | MPLY |      |      | |      |  x   | HOME | PGUP |  ←   |  →   |  Enter |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |  END | PGDN |  ↓   | Shft |      |
 *   '----------------------------------'                             '----------------------------------'
 *                                    .---------------. .---------------.
 *                                    |       |       | |       |       |
 *                            .-------+-------+-------| |-------+-------+-------.
 *                            |       |       |       | |       |       |       |
 *                            |       |       |-------| |-------|       |       |
 *                            |       |       |  #B1  | |  #B2  |       |       |
 *                            '-----------------------' '-----------------------'
 */
[_HL] = LAYOUT_ergodox(
      // left hand
      KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
      KC_CAPS, _______, _______, _______, _______, _______, DEBUG,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______,
      _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______, VRSN,
      _______, _______, _______, _______, _______,
                                                   _______, _______,
                                                            _______,
                                          _______, _______, PDF1,
      // right hand
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      RESET,   _______, _______, _______, _______, KC_INS,  KC_DEL,
               _______, KC_PSCR, KC_SLCK, KC_BRK,  KC_UP,   KC_BSPC,
      EPRM,    _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_ENT,
                        KC_END,  KC_PGDN, KC_DOWN, KC_RSFT, _______,
      _______, _______,
      _______,
      PDF2,    _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool pseudo_backspace_pressed = false;
    bool is_ctrl_pressed = get_mods() & MOD_BIT(KC_LCTRL);

    switch (keycode) {
        case PDF1:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_B1);
                layer_state_set_user(layer_state);
            }
            return false;
            break;
        case PDF2:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_B2);
                layer_state_set_user(layer_state);
            }
            return false;
            break;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case KC_H:
            if (!record->event.pressed && pseudo_backspace_pressed) {
                // Release a pseudo Backspace and press Ctrl
                pseudo_backspace_pressed = false;
                del_key(KC_BSPC);
                send_keyboard_report();
                add_mods(MOD_BIT(KC_LCTRL));
                send_keyboard_report();
                return false;
            }
            else if(record->event.pressed && is_ctrl_pressed) {
                // Relase Ctrl/H and press a pseudo Backspace
                pseudo_backspace_pressed = true;
                del_key(keycode);
                del_mods(MOD_BIT(KC_LCTRL));
                send_keyboard_report();
                add_key(KC_BSPC);
                send_keyboard_report();
                return false;
            }
            break;
        case KC_LCTRL:
        case KC_RCTRL:
        case K_SANDC:
            if (!record->event.pressed && pseudo_backspace_pressed) {
                // Release a pseudo Backspace and press H
                pseudo_backspace_pressed = false;
                del_key(KC_BSPC);
                del_mods(MOD_BIT(KC_LCTL));
                send_keyboard_report();
                add_key(KC_H);
                send_keyboard_report();
                return false;
            }
            break;
    }
    return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {}; 

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};

// Runs whenever there is a default layer state change.
uint32_t default_layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (biton32(state)) {
        case _B2:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    switch (biton32(layer_state)) {
        case _HL:
            ergodox_right_led_1_on();
            break;
        default:
            break;
    }
    return state;
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (biton32(default_layer_state)) {
        case _B2:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    switch (biton32(state)) {
        case _HL:
            ergodox_right_led_1_on();
            break;
        default:
            break;
    }
    return state;
};
