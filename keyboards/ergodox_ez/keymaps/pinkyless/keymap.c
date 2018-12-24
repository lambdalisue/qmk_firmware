#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _JS 0 // JIS layer
#define _US 1 // US layer
#define _HL 2 // HHKB fn like layer

// Layer
#define MO_HHKB  MO(_HL)     // HHKB Layer

// SandS
#define K_SANDC LCTL_T(KC_SPC)      // Space and Ctrl
#define K_RANDS LSFT_T(KC_ENT)      // Return and Shift
#define K_2ANDC LCTL_T(KC_LANG2)    // Lang2 (Eisuu) and Ctrl
#define K_1ANDS LSFT_T(KC_LANG1)    // Lang1 (Kana) and Shift
#define K_GANDS LSFT_T(KC_GRV)      // Grave and Shift
#define K_UANDS LSFT_T(KC_RO)       // Underscore (Ro) and Shift

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  PDFJS,
  PDFUS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* JIS layer
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |  Esc   |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------| BSPC |      |      |      |      |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |   !  |   "  |   #  |   $  |   %  |   &  | |  &   |  '   |  (   |  )   |      |  =   |   ~    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |   '  | |  %   |      |      |      |      |      |   `    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------|      |      |      |      |  +   |   *    |
 * |--------+------+------+------+------+------|   {  | |  }   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |  <   |  >   |  ?   |        |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |  ~   |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  | |  6   |  7   |  8   |  9   |  0   |  -   |   \    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |   7  | |  5   |  Y   |  U   |  I   |  O   |  P   |   @    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |   Ctl  |   A  |   S  |   D  |   F  |   G  |------| |------|  H   |  J   |  K   |  L   |  ;   |   :    |
 * |--------+------+------+------+------+------|   [  | |  ]   |------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |      | |      |  N   |  M   |  ,   |  .   |  /   |   _ [S]|
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   | HHKB | Caps | LAlt | LGui | L2[S]|                             | L1[C]| RGui | RAlt |  ^   |      |
 *   '----------------------------------'                             '----------------------------------'
 *                                    .---------------. .---------------.
 *                                    |  Gui  |  Alt  | |  INS  | SLCK  |
 *                            .-------+-------+-------| |-------+-------+-------.
 *                            |    [S]|       | PRSCR | | BREAK |       |    [C]|
 *                            | Space | Space |-------| |-------| Enter | Enter |
 *                            |       |       |  DEL  | | BSPC  |       |       |
 *                            '-----------------------' '-----------------------'
 */
[_JS] = LAYOUT_ergodox(
      // left hand
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RBRC,
      MO_HHKB, KC_CAPS, KC_LALT, KC_LGUI, K_2ANDC,
                                                   KC_RGUI, KC_RALT,
                                                            KC_PSCR,
                                          K_SANDC, KC_SPC,  KC_DEL,
      // right hand
      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_JYEN,
      KC_5,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_NUHS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, K_UANDS,
                        K_1ANDS, KC_RGUI, KC_RALT, KC_EQL,  KC_NO,
      KC_INS,  KC_SLCK,
      KC_BRK,
      KC_BSPC, KC_ENT,  K_RANDS
),

/* US layer
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |  Esc   |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------| BSPC |      |      |      |      |        |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |      |      |      |        |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |      |      |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |        |   !  |   @  |   #  |   $  |   %  |   ^  | |  ^   |  &   |  *   |  (   |  )   |  _   |   |    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |   &  | |  %   |      |      |      |      |      |   +    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------| |------|      |      |      |      |  :   |   "    |
 * |--------+------+------+------+------+------|   {  | |  }   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      | |      |      |      |  <   |  >   |  ?   |   ~    |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |      |  {   |   }  |
 *   '----------------------------------'                             '----------------------------------'
 * .--------------------------------------------------. .--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  | |  6   |  7   |  8   |  9   |  0   |  -   |   \    |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |   7  | |  5   |  Y   |  U   |  I   |  O   |  P   |   =    |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |   Ctl  |   A  |   S  |   D  |   F  |   G  |------| |------|  H   |  J   |  K   |  L   |  ;   |   '    |
 * |--------+------+------+------+------+------|   [  | |  ]   |------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |   {  | |  }   |  N   |  M   |  ,   |  .   |  /   |   ` [S]|
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   | HHKB | Caps | LAlt | LGui | L2[S]|                             | L1[C]| RGui | RAlt |  [   |   ]  |
 *   '----------------------------------'                             '----------------------------------'
 *                                    .---------------. .---------------.
 *                                    |  Gui  |  Alt  | |  INS  | SLCK  |
 *                            .-------+-------+-------| |-------+-------+-------.
 *                            |    [S]|       | PRSCR | | BREAK |       |    [C]|
 *                            | Space | Space |-------| |-------| Enter | Enter |
 *                            |       |       |  DEL  | | BSPC  |       |       |
 *                            '-----------------------' '-----------------------'
 */
[_US] = LAYOUT_ergodox(
      // left hand
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,
      MO_HHKB, KC_CAPS, KC_LALT, KC_LGUI, K_2ANDC,
                                                   KC_RGUI, KC_RALT,
                                                            KC_PSCR,
                                          K_SANDC, KC_SPC,  KC_DEL,
      // right hand
      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSLS,
      KC_5,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, K_GANDS,
                        K_1ANDS, KC_RGUI, KC_RALT, KC_LBRC, KC_RBRC,
      KC_INS,  KC_SLCK,
      KC_BRK,
      KC_BSPC, KC_ENT,  K_RANDS
),

/* HHKB layer
 * .--------------------------------------------------. .--------------------------------------------------.
 * |  Power |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------+------| |------+------+------+------+------+------+--------|
 * |  Caps  |      |      |      |      |      | DEBG | | REST |      | PSCR | SLCK | BRK  |  ↑   |  INS   |
 * |--------+------+------+------+------+------|      | |      |------+------+------+------+------+--------|
 * |        | VOLD | VOLU | MUTE | EJCT |      |------| |------|      | HOME | PGUP |  ←   |  →   |  DEL   |
 * |--------+------+------+------+------+------| VRSN | | EPRM |------+------+------+------+------+--------|
 * |        | MPRV | MNXT | MSTP | MPLY |      |      | |      |      |  END | PGDN |  ↓   | Shft |        |
 * '--------+------+------+------+------+-------------' '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                             |      |      |  DEL |  Gui | Ctrl |
 *   '----------------------------------'                             '----------------------------------'
 *                                    .---------------. .---------------.
 *                                    |       |       | |       |       |
 *                            .-------+-------+-------| |-------+-------+-------.
 *                            |       |       |       | | #US   |       |       |
 *                            |       |       |-------| |-------|       |       |
 *                            |       |       |       | | #JIS  |       |       |
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
                                          _______, _______, PDFJS,
      // right hand
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      RESET,   _______, KC_PSCR, KC_SLCK, KC_BRK,  KC_UP,   KC_INS,
               _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_DEL,
      EPRM,    _______, KC_END,  KC_PGDN, KC_DOWN, KC_RSFT, _______,
                        _______, _______, KC_DEL,  KC_RGUI, KC_RCTL,
      _______, _______,
      _______,
      PDFUS,   _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool pseudo_escape_pressed = false;
    static bool pseudo_backspace_pressed = false;
    bool is_ctrl_pressed = get_mods() & MOD_BIT(KC_LCTRL);
    bool is_jis_layer = biton32(default_layer_state) == _JS;

    switch (keycode) {
        case PDFJS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_JS);
                layer_state_set_user(layer_state);
            }
            return false;
            break;
        case PDFUS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_US);
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
        case KC_LBRC:
        case KC_EQL:
            if ((keycode == KC_LBRC && !is_jis_layer) || (keycode == KC_EQL && is_jis_layer)) {
                return true;
            }
            else if (!record->event.pressed && pseudo_escape_pressed) {
                // Release a pseudo Escape and press Ctrl
                pseudo_escape_pressed = false;
                del_key(KC_ESC);
                send_keyboard_report();
                add_mods(MOD_BIT(KC_LCTRL));
                send_keyboard_report();
                return false;
            }
            else if(record->event.pressed && is_ctrl_pressed) {
                // Release Ctrl/= and press a pseudo Escape
                pseudo_escape_pressed = true;
                del_key(keycode);
                del_mods(MOD_BIT(KC_LCTRL));
                send_keyboard_report();
                add_key(KC_ESC);
                send_keyboard_report();
                return false;
            }
            break;
        case KC_LCTRL:
        case KC_RCTRL:
        case K_SANDC:
        case K_2ANDC:
            if (!record->event.pressed && pseudo_escape_pressed) {
                // Release a pseudo Escape and press =
                pseudo_escape_pressed = false;
                del_key(KC_ESC);
                del_mods(MOD_BIT(KC_LCTL));
                send_keyboard_report();
                add_key(is_jis_layer ? KC_LBRC : KC_EQL);
                send_keyboard_report();
                return false;
            }
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
        case _US:
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
        case _US:
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
