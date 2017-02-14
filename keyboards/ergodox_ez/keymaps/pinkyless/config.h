#ifndef KEYBOARDS_ERGODOX_EZ_PINKYLESS_CONFIG_H_
#define KEYBOARDS_ERGODOX_EZ_PINKYLESS_CONFIG_H_
#include "../../config.h"

// Redefine Magic key combination while L_Shift + R_Shift is difficult
// for 'pinkyless' mapping
#undef IS_COMMAND
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)) \
)

// Prefer to hold a modifier key after tap->hold
#define TAPPING_FORCE_HOLD

#endif /* KEYBOARDS_ERGODOX_EZ_PINKYLESS_CONFIG_H_ */
