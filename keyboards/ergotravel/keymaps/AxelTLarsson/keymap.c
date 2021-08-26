#include QMK_KEYBOARD_H


// Layers
enum layers {
    _QWERTY = 0,
    _SYM,
    _SYS,
    _ADJUST
};

// all modifiers should be modtap!
#define KC_MYCTL MT(MOD_RCTL, KC_ENT)
#define KC_MYSYM LT(_SYM, KC_TAB)
#define KC_MYALT MT(MOD_RALT, KC_TAB)
#define KC_MYGUI MT(MOD_LGUI, KC_F3)
#define KC_MYSFT MT(MOD_LSFT, KC_BSPC)
#define KC_MYTAB LT(_SYS, KC_ESC)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Swedish keybord special signs
#define KC_ARING KC_LBRC
#define KC_OUML KC_SCLN
#define KC_AUML KC_QUOT
#define KC_SE_SLSH S(KC_7)
#define KC_SE_AT RALT(KC_2)
#define KC_SE_AMPR S(KC_6)
#define KC_SE_LPRN S(KC_8)
#define KC_SE_RPRN S(KC_9)
#define KC_SE_QUOT KC_BSLS
#define KC_SE_DQUO S(KC_2)
#define KC_SE_DLR RALT(KC_4)
#define KC_SE_LCBR S(RALT(KC_8))
#define KC_SE_RCBR S(RALT(KC_9))
#define KC_SE_LBRC RALT(KC_8)
#define KC_SE_RBRC RALT(KC_9)
#define KC_SE_EQL S(KC_0)
#define KC_SE_GBP RALT(KC_3)
#define KC_SE_TILD RALT(KC_RBRC)
#define KC_SE_EURO RALT(KC_E)
#define KC_SE_AA KC_LBRC
#define KC_SE_OE KC_SCLN
#define KC_SE_AE KC_QUOT
#define KC_SE_PLAYP KC_MEDIA_PLAY_PAUSE
#define KC_SE_MUTE KC_AUDIO_MUTE
#define KC_SE_CIRC KC_RCBR
#define KC_SE_PARA KC_GRAVE
#define KC_SE_HALF KC_TILD
#define KC_SE_ACUT KC_EQL
#define KC_SE_GRAV KC_PLUS
#define KC_SE_GT S(KC_GRV)
#define KC_SE_LT KC_GRV
#define KC_SE_PLUS KC_MINS
#define KC_SE_ASTR KC_PIPE
#define KC_SE_QUES S(KC_MINS)
#define KC_SE_BSLS S(RALT(KC_7))
#define KC_SE_PIPE RALT(KC_7)
#define KC_SE_SCLN S(KC_COMM)
#define KC_SE_COLN S(KC_DOT)
#define KC_SE_MINS KC_SLSH
#define KC_SE_UNDS S(KC_SLSH)

enum custom_keycodes {
  SYM = SAFE_RANGE,
  SYS,
  ANSIKEY,
  ANSICOM,
  ANSIDOT,
  MY_SCREENSHOT,
  M_ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* Base Layer: QWERTY
   *
   *   ,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   *   |  SYS   |    Q   |   W    |   E    |   R    |   T    |        |        |        |   Y    |    U   |    I   |    O   |   P    |    Å   |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |  Esc   |    A   |   S    |   D    |   F    |   G    |        |        |        |   H    |    J   |    K   |    L   |   Ö    |    Ä   |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |  Shift |    Z   |   X    |   C    |   V    |   B    | LShift |        | SYS    |   N    |    M   |   , <  |   . >  |  / ?   |  Shift |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |        |        |        | Ctrl   |  CMD   | Tab    | Bspc   |        | Enter  | Space  |   Alt  |        |        |        |  Shift |
   *   |        |        |        |        |  (F3)  | SYM    | Shift  |        | Ctrl   |        |  (Tab) |        |        |        |        |
   *   `--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
   */
  [_QWERTY] = LAYOUT(
     KC_MYTAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,            _______,  KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_ARING,
     KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,            _______,  KC_H,    KC_J,   KC_K,     KC_L,    KC_OUML, KC_AUML,
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT,            KC_MYTAB, KC_N,    KC_M,   ANSICOM,  ANSIDOT, ANSIKEY, KC_LSFT,
     _______,  _______, KC_LCTL, KC_MYGUI,         KC_MYSYM,KC_MYSFT,           KC_MYCTL, KC_SPC,          KC_MYALT, _______, _______, KC_LSFT
  ),


  /* Symbol Layer
   *
   *   ,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   *   |   `    |   !    |   @    |   {    |   }    |   &    |        |        |        |   *    |   7    |   8    |   9    |   0    |   =    |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |   ~    |   ^    |   $    |   (    |   )    |   '    |        |        |        |   ;    |   4    |   5    |   6    |   -    |   _    |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |   |    |   #    |   %    |   [    |   ]    |   "    |        |        |        |   :    |   1    |   2    |   3    |   \    |   ->   |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |        |        |        |        |        |        |        |        |   0    |   0    |   0    |   0    |        |        |        |
   *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
   *   `--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
   */
  [_SYM] = LAYOUT(
     KC_SE_GRAV,KC_EXLM,   KC_SE_AT, KC_SE_LCBR,KC_SE_RCBR,KC_SE_AMPR,_______,     _______,  KC_SE_ASTR, KC_7,   KC_8,  KC_9,   KC_SE_PLUS, KC_SE_EQL,
     KC_SE_TILD,KC_SE_CIRC,KC_SE_DLR,KC_SE_LPRN,KC_SE_RPRN,KC_SE_QUOT,_______,     _______,  KC_SE_SCLN, KC_4,   KC_5,  KC_6,   KC_SE_MINS, KC_SE_UNDS,
     KC_SE_PIPE,KC_HASH,   KC_PERC,  KC_SE_LBRC,KC_SE_RBRC,KC_SE_DQUO,_______,     _______,  KC_SE_COLN, KC_1,   KC_2,  KC_3,   KC_SE_BSLS, M_ARROW,
     _______, _______, _______, _______,          _______, _______,                KC_0,       KC_0,             KC_0, _______, _______,  _______
  ),

 /* System Layer: Number keys, media, navigation
  *
  *   ,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
  *   |        |   1    |   2    |   3    |   4    |   5    |        |        |        |   6    |   7    |   8    |   9    |   0    |        |
  *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
  *   |        |        |  Prev  |  Play  |  Next  |  VolUp |        |        |        |  Left  |  Down  |   Up   |  Right |        |        |
  *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
  *   |        |        |        |        |  Mute  |  VolDn |        |        |        |        |  BrDn  |  BrUp  |        |        |        |
  *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
  *   `--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  */
 [_SYS] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,            _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, _______,            _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______,            _______,  _______, KC_BRID, KC_BRIU, _______, _______, _______,
    _______, _______, _______, _______,          _______, _______,            _______,  _______,          _______, _______, _______, _______
 ),


  /* Adjust Layer: Function Keys, RGB
   *
   *   ,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   *   |  SYS   |    Q   |   W    |   E    |   R    |   T    |        |        |        |   Y    |    U   |    I   |    O   |   P    |    Å   |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |  Esc   |    A   |   S    |   D    |   F    |   G    |        |        |        |   H    |    J   |    K   |    L   |   Ö    |    Ä   |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |  Shift |    Z   |   X    |   C    |   V    |   B    | LShift |        | SYS    |   N    |    M   |   , <  |   . >  |  / ?   |  Shift |
   *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   *   |        |        |        | Ctrl   |  CMD   | Tab    | Bspc   |        | Enter  | Space  |   Alt  |  Ctrl  |        |        |        |
   *   |        |        |        |        |  (F3)  | SYM    | Shift  |        | Ctrl   |        |  (Tab) |        |        |        |        |
   *   `--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
   */
  [_ADJUST] = LAYOUT(
     _______,  _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, _______,
     _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG,
     _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, _______, _______, _______, _______, BL_STEP,
     _______, _______, _______, _______,           _______, _______,         _______,  _______,          _______, _______, _______, RESET
  )


// /* Layer template
//  *
//  *   ,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
//  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
//  *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
//  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
//  *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
//  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
//  *   |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
//  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
//  *   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
//  *   `--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
//  */
// [_LAYERINDEX] = LAYOUT(
//    _______, _______, _______, _______, _______, _______, _______,            _______,  _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,            _______,  _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,            _______,  _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______,          _______, _______,            _______,  _______,          _______, _______, _______, _______
// ),

};





// Runs every time that the layers get changed. This can be useful for layer indication, or custom layer handling.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _SYS, _ADJUST);
}

// Handle ANSI keys - from johannes-jansson
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t shift_pressed = get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
  // uint8_t alt_pressed = get_mods() & ((MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)));

  switch (keycode) {
    case ANSIKEY: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_MINS);
        } else {
          register_code(KC_LSHIFT);
          register_code(KC_7);
          unregister_code(KC_LSHIFT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_MINS);
        } else {
          unregister_code(KC_7);
        }
      return false;
    }
    case ANSICOM: {
      if (record->event.pressed)
        if(shift_pressed) {
          unregister_code(KC_LSHIFT);
          register_code(KC_GRV);
          register_code(KC_LSHIFT);
        } else {
          register_code(KC_COMM);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_COMM);
        }
      return false;
    }
    case ANSIDOT: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_GRV);
        } else {
          register_code(KC_DOT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_DOT);
        }
      return false;
    }
    case MY_SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT(SS_TAP(X_4)))));
      }
      return false;
      break;
    case M_ARROW:
      if (record->event.pressed) {
        SEND_STRING("/" SS_LSFT("`")); // ->
      }
      return false;
      break;
    // The following handle layer switching
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;
  }
  return true;
}
