#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

const uint8_t rowsCount = 6;
const uint8_t rows[rowsCount] = {39, 38, 37, 36, 35, 34};

const uint8_t columnsCount = 14;                                                           
const uint8_t columns[columnsCount] = {17, 16, 15, 14, 13, 24, 25, 26, 27, 28, 29, 30, 31, 32};
                                    // c0  c1  c2  c3  c4  c5  c6  c7  c8  c9  10  11  12  13 
                                                                        
struct Key {
  uint8_t row;
  uint8_t column;
  boolean pressed;
};

const uint16_t LAYER_1                       = 1 | 0xA000;
const uint16_t LAYER_2                       = 2 | 0xA000;
const uint16_t LAYER_3                       = 3 | 0xA000;
const uint16_t LAYER_4                       = 4 | 0xA000;
const uint16_t LAYER_0CAPS                   = 6 | 0xA000;
const uint16_t LAYER_MIRROR                  = 7 | 0xA000;
const uint16_t LAYER_ALT                     = 8 | 0xA000;
const uint16_t LAYER_ALT2                    = 9 | 0xA000;
//const uint16_t                               = 10 | 0xA000;

const uint16_t KEY_RELEASE                   = 14 | 0xA000;
const uint16_t KEY_SET0                      = 15 | 0xA000;
const uint16_t KEY_NULL                      = 16 | 0xA000;

const uint16_t EXCLAMATION                   = 17 | 0xA000; // !
const uint16_t KEY_AT                        = 18 | 0xA000; // @
const uint16_t KEY_HASH                      = 19 | 0xA000; // #
const uint16_t KEY_DOLLAR                    = 20 | 0xA000; // $
const uint16_t KEY_PERCENT                   = 21 | 0xA000; // %
const uint16_t KEY_CARAT                     = 22 | 0xA000; // ^
const uint16_t AMPERSAND                     = 23 | 0xA000; // &
const uint16_t KEY_ASTERISK                  = 24 | 0xA000; // *
const uint16_t L_PARENTHESIS                 = 25 | 0xA000; // (
const uint16_t R_PARENTHESIS                 = 26 | 0xA000; // )
const uint16_t UNDERSCORE                    = 27 | 0xA000; // _
const uint16_t KEY_PIPE                      = 28 | 0xA000; // |
const uint16_t LEFT_CHEVRON                  = 29 | 0xA000; // <
const uint16_t RIGHT_CHEVRON                 = 30 | 0xA000; // >
const uint16_t QUESTION_MARK                 = 31 | 0xA000; // ?
const uint16_t KEY_COLON                     = 32 | 0xA000; // :
const uint16_t KEY_DBLQUOTE                  = 33 | 0xA000; // "
const uint16_t CURL_L_BRACE                  = 34 | 0xA000; // {
const uint16_t CURL_R_BRACE                  = 35 | 0xA000; // }
const uint16_t SHIFT_TILDE                   = 36 | 0xA000; // ~
const uint16_t KEY_PLUS                      = 37 | 0xA000; // +
const uint16_t KEY_DEGREES                   = 39 | 0xA000; // °
const uint16_t KEY_VOL_UP_5                  = 40 | 0xA000;
const uint16_t KEY_VOL_DOWN_5                = 41 | 0xA000;
const uint16_t KEY_MUTE                      = 42 | 0xA000;
const uint16_t TRILL_MODE1                   = 43 | 0xA000;
const uint16_t TRILL_MODE2                   = 44 | 0xA000;
const uint16_t TRILL_MODE3                   = 45 | 0xA000;
const uint16_t KEY_ALT_TAB                   = 46 | 0xA000;
const uint16_t KEY_PREV                      = 47 | 0xA000;
const uint16_t KEY_NEXT                      = 48 | 0xA000;
const uint16_t KEY_RW                        = 49 | 0xA000;
const uint16_t KEY_FF                        = 50 | 0xA000;
const uint16_t KEY_REC                       = 51 | 0xA000;
const uint16_t KEY_REBOOT                    = 52 | 0xA000;
const uint16_t KEY_ALTx                      = 53 | 0xA000;
const uint16_t KEY_ALTy                      = 54 | 0xA000;
const uint16_t KEY_GM0                       = 55 | 0xA000;
const uint16_t KEY_GM1                       = 56 | 0xA000;
const uint16_t MOUSE_LCLICK                  = 57 | 0xA000;
const uint16_t KEY_PLAY_PAUSE                = 58 | 0xA000;
const uint16_t KEY_VOL_UP                    = 59 | 0xA000;
const uint16_t KEY_VOL_DOWN                  = 60 | 0xA000;
const uint16_t MOUSE_RCLICK                  = 61 | 0xA000;
const uint16_t LEDS_BR0                      = 62 | 0xA000;
const uint16_t LEDS_BR1                      = 63 | 0xA000;
const uint16_t LEDS_BR2                      = 64 | 0xA000;
const uint16_t LEDS_BR3                      = 65 | 0xA000;
const uint16_t LEDS_BR4                      = 66 | 0xA000;
const uint16_t LEDS_BR5                      = 67 | 0xA000;
const uint16_t LEDS_BR6                      = 68 | 0xA000;
const uint16_t LEDS_BR7                      = 69 | 0xA000;
const uint16_t LEDS_BR8                      = 70 | 0xA000;
const uint16_t LEDS_BR9                      = 71 | 0xA000;
const uint16_t LEDS_BR10                     = 72 | 0xA000;
const uint16_t LEDS_INC                      = 73 | 0xA000;
const uint16_t LEDS_DEC                      = 74 | 0xA000;
const uint16_t MACRON_E                      = 75 | 0xA000;

const uint16_t KEYSF13                       = 113 | 0xA000;
const uint16_t KEYSF14                       = 114 | 0xA000;
const uint16_t KEYSF15                       = 115 | 0xA000;
const uint16_t KEYSF16                       = 116 | 0xA000;
const uint16_t KEYSF17                       = 117 | 0xA000;
const uint16_t KEYSF18                       = 118 | 0xA000;
const uint16_t KEYSF19                       = 119 | 0xA000;
const uint16_t KEYSF20                       = 120 | 0xA000;
const uint16_t KEYSF21                       = 121 | 0xA000;
const uint16_t KEYSF22                       = 122 | 0xA000;
const uint16_t KEYSF23                       = 123 | 0xA000;
const uint16_t KEYSF24                       = 124 | 0xA000;



struct LayoutKey {
  uint16_t code;
};

#endif
