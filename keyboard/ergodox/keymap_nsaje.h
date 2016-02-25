static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(
        // Left Hand
        GRV, 1,   2,   3,   4,   5,   6,
        TAB, Q,   W,   E,   R,   T,   LBRC,
        LCTL,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   ESC,
        LCTL,NO, NO,LGUI,LALT,
                                      DEL,LALT,
                                           PGUP,
                                  BSPC,ESC, PGDN,
        // Right Hand
            NO,   7,   8,   9,   0,   MINS,   EQL,
            RBRC, Y,   U,   I,   O,   P,   LBRC,
                  H,   J,   K,   L,   SCLN,   QUOT,
            QUOT,  N,   M,   COMM,DOT, SLSH,   RSFT,
                       FN1,RCTL, FN2, RGHT,   BSLS,
        RALT, RCTL,
        HOME,
        END, ENT,SPC
    ),

// qwerty with staggered bottom row
    KEYMAP( // Layer 1
        // Left Hand
        TRNS, 1,   2,   3,   4,   5,   6,
        TRNS, Q,   W,   E,   R,   T,   LBRC,
        TRNS,A,   S,   D,   F,   G,
        TRNS,LSFT, Z,  X,   C,   V,   B,
        TRNS,TRNS, TRNS,TRNS, TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                  TRNS,TRNS, TRNS,
        // Right Hand
            NO, 7,   8,   9,   0,   MINS,  EQL,
            RBRC, Y,   U,   I,   O,   P,   TRNS,
                  H,   J,   K,   L,   SCLN,   TRNS,
            QUOT,  N,   M,   COMM,DOT,  TRNS, TRNS,
                       TRNS,TRNS, TRNS, TRNS,   TRNS,
        TRNS, TRNS,
        TRNS,
        TRNS, TRNS,TRNS
    ),

    KEYMAP(  // Layer2: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        FN0,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  E,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                  TRNS,TRNS, TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  U,  NO,  NO,  NO,  TRNS,
                  LEFT,  DOWN,  UP,  RGHT,  TRNS, TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       TRNS,TRNS, TRNS, TRNS,   TRNS,
        TRNS, TRNS,
        TRNS,
        TRNS, TRNS, TRNS
    ),

/*
    // templates to copy from

    KEYMAP(  // LayerN: transparent on edges + hard-defined thumb keys, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

// https://github.com/jcheng31/tmk_keyboard/blob/colemak/keyboard/ergodox/keymap_colemak.h
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY), // Teensy
    ACTION_LAYER_MOMENTARY(2), // Hold for Programming Layer
    ACTION_LAYER_INVERT(1, ON_PRESS), // Push to enable/disable staggered qwerty layer
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}


