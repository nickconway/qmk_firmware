#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

#define PREV_DESK LCTL(LGUI(KC_LEFT))
#define NEXT_DESK LCTL(LGUI(KC_RIGHT))
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK

#define GAMEZ LT(GAMETWO, KC_Z)

enum layers {
    BASE,
    NAVL,
    MOUSEL,
    MEDIAL,
    NUMR,
    SYMR,
    FUNCR,
    GAME,
    GAMETWO,
    QWERTY,
    QGAME,
    STENO
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    RGB_SLD,
    WHEEL = SAFE_RANGE
};



enum tap_dances {
    TD_Q_TAB = 0
};

void danceQTab(qk_tap_dance_state_t* state, void* user_data){
    if(state->count >= 2){
        register_code(KC_TAB);
    } else {
        register_code(KC_Q);
    }
}

void danceQTabReset(qk_tap_dance_state_t* state, void* user_data){
    if(state->count >= 2){
        unregister_code(KC_TAB);
    } else {
        unregister_code(KC_Q);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(danceQTab, NULL, danceQTabReset)
};



// tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_T):
        case LCTL_T(KC_N):
        case LCTL_T(KC_J):
        case LCTL_T(KC_F):
            return TAPPING_TERM;

        case LALT_T(KC_S):
        case LALT_T(KC_E):
        case LALT_T(KC_D):
        case LALT_T(KC_K):
            return TAPPING_TERM;

        case LGUI_T(KC_R):
        case LGUI_T(KC_I):
        case LGUI_T(KC_S):
        case LGUI_T(KC_L):
            return TAPPING_TERM + 25;

        case LSFT_T(KC_A):
        case LSFT_T(KC_SCOLON):
        case LSFT_T(KC_O):
            return TAPPING_TERM + 50;

        default:
            return TAPPING_TERM;
    }
};

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_A):
        case LSFT_T(KC_O):
        case LSFT_T(KC_SCOLON):
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_A):
        case LGUI_T(KC_R):
        case LALT_T(KC_S):
        case LCTL_T(KC_T):
        case LCTL_T(KC_N):
        case LALT_T(KC_E):
        case LGUI_T(KC_I):
        case LSFT_T(KC_O):
        case LGUI_T(KC_S):
        case LALT_T(KC_D):
        case LCTL_T(KC_F):
        case LCTL_T(KC_J):
        case LALT_T(KC_K):
        case LGUI_T(KC_L):
        case LSFT_T(KC_SCOLON):
            return false;
        default:
            return true;
    }
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_A):
        case LSFT_T(KC_O):
        case LSFT_T(KC_SCOLON):
            return true;
        default:
            return false;
    }
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_A):
        case LGUI_T(KC_R):
        case LALT_T(KC_S):
        case LCTL_T(KC_T):
        case LCTL_T(KC_N):
        case LALT_T(KC_E):
        case LGUI_T(KC_I):
        case LSFT_T(KC_O):
        case LGUI_T(KC_S):
        case LALT_T(KC_D):
        case LCTL_T(KC_F):
        case LCTL_T(KC_J):
        case LALT_T(KC_K):
        case LGUI_T(KC_L):
        case LSFT_T(KC_SCOLON):
            return true;
        default:
            return false;
    }
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    WHEEL,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(QWERTY),
        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,
        LSFT_T(KC_A),   LGUI_T(KC_R),   LALT_T(KC_S),   LCTL_T(KC_T),   KC_G,           KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_M,           LCTL_T(KC_N),   LALT_T(KC_E),   LGUI_T(KC_I),   LSFT_T(KC_O),
        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,
        KC_TRANSPARENT, KC_TRANSPARENT, LT(5,KC_ESCAPE),LT(6,KC_TAB),   LT(4,KC_BSPACE),                                                                                                                   LT(1,KC_SPACE), LT(3,KC_ENTER), LT(2,KC_DELETE),KC_TRANSPARENT, TG(GAME),
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                         KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, LT(2,KC_DELETE)
    ),
    [NAVL] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, RESET,
        KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_CAPSLOCK,    KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,
        KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_INSERT,      KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, NEXT_DESK,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [MOUSEL] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_UP,       KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,
        KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_TRANSPARENT, KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,                                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [MEDIAL] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_AUDIO_MUTE,  PREV_TRACK,     NEXT_TRACK,     KC_TRANSPARENT, KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,
        RGB_VAI,        RGB_SAI,        RGB_HUI,        RGB_MOD,        RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,                                                                                                               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [NUMR] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,
        KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_EQUAL,       KC_4,           KC_5,           KC_6,           KC_SCOLON,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, PREV_DESK,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLASH,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                                    KC_0,           KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS
    ),
    [SYMR] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,
        KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_PLUS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_COLN,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                                    KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS
    ),
    [FUNCR] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCREEN,     KC_F7,          KC_F8,          KC_F9,          KC_F12,
        KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_SCROLLLOCK,  KC_F4,          KC_F5,          KC_F6,          KC_F11,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_PAUSE,       KC_F1,          KC_F2,          KC_F3,          KC_F10,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [GAME] = LAYOUT_ergodox_pretty(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_J,           KC_EQUAL,                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_A,           KC_R,           KC_S,           KC_T,           KC_TRANSPARENT, KC_M,                                                                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        GAMEZ,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_K,           KC_MINUS,                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_SPACE,                                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [GAMETWO] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_J,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [QWERTY] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        LSFT_T(KC_A),   LGUI_T(KC_S),   LALT_T(KC_D),   LCTL_T(KC_F),   KC_G,           KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_H,           LCTL_T(KC_J),   LALT_T(KC_K),   LGUI_T(KC_L),   LSFT_T(KC_SCLN),
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,
        TG(STENO),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(9),
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [QGAME] = LAYOUT_ergodox_pretty(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_EQUAL,                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,                                                                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_MINUS,                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_SPACE,                                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [STENO] = LAYOUT_ergodox_pretty(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT, KC_TRANSPARENT,                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        LSFT_T(KC_A),   LGUI_T(KC_S),   LALT_T(KC_D),   LCTL_T(KC_F),   KC_G,           KC_TRANSPARENT,                                                                                    KC_TRANSPARENT, KC_H,           LCTL_T(KC_J),   LALT_T(KC_K),   LGUI_T(KC_L),   LSFT_T(KC_SCLN),
        KC_Z,           KC_X,           KC_C,           KC_C,           KC_V,                                                                                                                              KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT,                    KC_TRANSPARENT,
                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    )
};



LEADER_EXTERNS();
void matrix_scan_user(void) {

    LEADER_DICTIONARY() {}

};

void leader_start(){
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
};

void leader_end(){
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
};


static bool wheelActive = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case WHEEL:
            wheelActive = !wheelActive;
            if(wheelActive){
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                register_code(KC_MS_WH_DOWN);
            } else {
                unregister_code(KC_MS_WH_DOWN);
            }
            return false;
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        #ifdef RGBLIGHT_ENABLE
            case RGB_SLD:
            rgblight_mode(1);
            return false;
        #endif
        }
    }

    return true;
};



// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    #ifdef RGBLIGHT_COLOR_LAYER_0
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
    #endif
};



// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);

  switch(layer){
    case GAME:
    case GAMETWO:
    case QGAME:
      combo_disable();
      autoshift_disable();
      break;
    default:
      combo_enable();
      autoshift_enable();
      break;
  }

  switch (layer) {
      case NAVL:
        ergodox_right_led_1_on();
        break;
      case MOUSEL:
        ergodox_right_led_2_on();
        break;
      case MEDIAL:
        ergodox_right_led_3_on();
        break;
      case NUMR:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case SYMR:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case FUNCR:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case GAME:
      case GAMETWO:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case QWERTY:
        ergodox_right_led_1_on();
        break;
      case QGAME:
        ergodox_right_led_2_on();
        break;
      default:
        break;
    }
  return state;
};
