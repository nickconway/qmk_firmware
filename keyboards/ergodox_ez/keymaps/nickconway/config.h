#define ORYX_CONFIGURATOR

#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    80
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

#undef TAPPING_TERM
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_ALPHA

#define LEADER_TIMEOUT 200
#define LEADER_NO_TIMEOUT

#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY
// #define RETRO_SHIFT 800
#define BILATERAL_COMBINATIONS

#undef DEBOUNCE
#define DEBOUNCE 1
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO
