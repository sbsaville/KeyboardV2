//#include <Bounce2.h>

#include <Trill.h>
#include <Mouse.h>

#include "main.h"
#include "rgbleds.h"
#include "layers.h"
#include "trillbar.h"

bool L_1 = 0;
bool L_2 = 0;
bool L_3 = 0;
bool L_4 = 0;
bool L_0CAPS = 0;
bool L_MIRROR = 0;
bool L_ALT = 0;
bool L_ALT2 = 0;

LayoutKey (*currentLayout)[columnsCount] = layout0;

Key keys[rowsCount][columnsCount] = {
 {{0, 0, false},{0, 1, false},{0, 2, false},{0, 3, false},{0, 4, false},{0, 5, false},{0, 6, false},{0, 7, false},{0, 8, false},{0, 9, false},{0, 10, false},{0, 11, false},{0, 12, false},{0, 13, false}},
 {{1, 0, false},{1, 1, false},{1, 2, false},{1, 3, false},{1, 4, false},{1, 5, false},{1, 6, false},{1, 7, false},{1, 8, false},{1, 9, false},{1, 10, false},{1, 11, false},{1, 12, false},{1, 13, false}},
 {{2, 0, false},{2, 1, false},{2, 2, false},{2, 3, false},{2, 4, false},{2, 5, false},{2, 6, false},{2, 7, false},{2, 8, false},{2, 9, false},{2, 10, false},{2, 11, false},{2, 12, false},{2, 13, false}},
 {{3, 0, false},{3, 1, false},{3, 2, false},{3, 3, false},{3, 4, false},{3, 5, false},{3, 6, false},{3, 7, false},{3, 8, false},{3, 9, false},{3, 10, false},{3, 11, false},{3, 12, false},{3, 13, false}},
 {{4, 0, false},{4, 1, false},{4, 2, false},{4, 3, false},{4, 4, false},{4, 5, false},{4, 6, false},{4, 7, false},{4, 8, false},{4, 9, false},{4, 10, false},{4, 11, false},{4, 12, false},{4, 13, false}},
 {{5, 0, false},{5, 1, false},{5, 2, false},{5, 3, false},{5, 4, false},{5, 5, false},{5, 6, false},{5, 7, false},{5, 8, false},{5, 9, false},{5, 10, false},{5, 11, false},{5, 12, false},{5, 13, false}}
};

Key* getKey(uint8_t row, uint8_t column) {
  return &keys[row][column];
}

LayoutKey* getLayoutKey(uint8_t row, uint8_t column) {
  return &currentLayout[row][column];
}

void sendKeys() {
//  if (!debug) {
    Keyboard.send_now();
//  }
}

void L_check() {
  Serial.print("L_1=");      Serial.print(L_1);      Serial.print(" "); 
  Serial.print("L_2=");      Serial.print(L_2);      Serial.print(" ");
  Serial.print("L_3=");      Serial.print(L_3);      Serial.print(" "); 
  Serial.print("L_4=");      Serial.print(L_4);      Serial.print(" "); 
  Serial.print("L_0CAPS=");  Serial.print(L_0CAPS);  Serial.print(" "); 
  Serial.print("L_MIRROR="); Serial.print(L_MIRROR); Serial.print(" "); 
  Serial.print("L_ALT=");    Serial.print(L_ALT);    Serial.print(" ");
  Serial.print("L_ALT2=");   Serial.print(L_ALT2);   Serial.println("");
}

void setup() {

  Serial.begin(115200);

  for (uint8_t j=0; j<columnsCount; j++) {
    pinMode(columns[j], INPUT_PULLUP);                 
  }

  for (uint8_t i=0; i<rowsCount; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
  }

  trillbar::setup();
  rgbleds::setup();

  Keyboard.begin();
  Mouse.begin();
}

void loop() {

  for (uint8_t i=0; i<rowsCount; i++) {
    digitalWrite(rows[i], LOW);

    for (uint8_t j=0; j<columnsCount; j++) {
      Key* key = getKey(i, j);

      boolean current = !digitalRead(columns[j]);
      boolean previous = key->pressed;
      key->pressed = current;

      LayoutKey* layout = getLayoutKey(key->row, key->column);

      if (current && !previous) {
        keyPressed(key, layout);
      } else if (!current && previous) {
        keyReleased(key, layout);
      }
    }

    digitalWrite(rows[i], HIGH);
    delayMicroseconds(5000);                  // sets polling rate to 200hz
  }

  trillbar::loop();
  rgbleds::loop();

                                           // active layer management

  if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_0CAPS == 0 && L_MIRROR == 0 && L_ALT == 0 && L_ALT2 == 0) {
    currentLayout = layout0;
    leds0();
    capscheck();
    trillMode = 1;
  }
  else if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_0CAPS == 1 && L_MIRROR == 0 && L_ALT == 0 && L_ALT2 == 0) {
    currentLayout = layout0mirror;
    leds0mirror();
    trillMode = 1;
  }
  else if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_0CAPS == 0 && L_MIRROR == 0 && L_ALT == 1 && L_ALT2 == 0) {
    currentLayout = layout0alt;
    leds0alt();
    trillMode = 1;
  }
  else if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_0CAPS == 0 && L_MIRROR == 0 && L_ALT == 0 && L_ALT2 == 1) {
    currentLayout = layout0alt2;
    leds0alt2();
    trillMode = 1;
  }
  else if (L_MIRROR == 1) {
    currentLayout = layoutMirror;
    ledsMirror();
  }
  else if (L_1 == 1 && L_2 == 0) {
    currentLayout = layout1;
    leds1();
    trillMode = 3;
  }
  else if (L_1 == 1 && L_2 == 1) {
    currentLayout = layout1_2;
    leds1_2();
  }
  else if (L_1 == 0 && L_2 == 1 && L_3 == 0) {
    currentLayout = layout2;
    leds2();
    trillMode = 2;
  }
  else if (L_2 == 1 && L_3 == 1) {
    currentLayout = layout2_3;
    leds2_3();
  }
  else if (L_3 == 1 && L_2 == 0 && L_4 == 0) {
    currentLayout = layout3;
    leds3();
  }
  else if (L_3 == 1 && L_4 == 1) {
    currentLayout = layout3_4;
    leds3_4();
  }
  else if (L_4 == 1) {
    currentLayout = layout4;
    leds4();
  }

}
                                                         // All of the operations to be performed on key press
void keyPressed(Key* key, LayoutKey* layout) {
  if (layout->code == KEY_NULL) {
  }
  else if (layout->code == LEDS_BR0) {
    brightness = brt0;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR1) {
    brightness = brt1;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR2) {
    brightness = brt2;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR3) {
    brightness = brt3;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR4) {
    brightness = brt4;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR5) {
    brightness = brt5;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR6) {
    brightness = brt6;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR7) {
    brightness = brt7;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR8) {
    brightness = brt8;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR9) {
    brightness = brt9;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_BR10) {
    brightness = brt10;
    LEDS.setBrightness(brightness);
    FastLED.show();
  }
  else if (layout->code == LEDS_INC) {
    if (brightness <= 32) {
      brightness = brightness + 1;
      LEDS.setBrightness(brightness);
      FastLED.show();
    }
    else if (brightness > 32) {
      brightness = brightness + 16;
      LEDS.setBrightness(brightness);
      FastLED.show();
    }
  }
  else if (layout->code == LEDS_DEC) {
    if (brightness > 1 && brightness <= 32) {
      brightness = brightness - 1;
      LEDS.setBrightness(brightness);
      FastLED.show();
    }
    else if (brightness > 32) {
      brightness = brightness - 16;
      LEDS.setBrightness(brightness);
      FastLED.show();
    }
    else if (brightness = 1) {
    }
  }
  else if (layout->code == TRILL_MODE1) {
    trillMode = 1;
  }
  else if (layout->code == TRILL_MODE2) {
    trillMode = 2;
  }
  else if (layout->code == TRILL_MODE3) {
    trillMode = 3;
  }
  else if (layout->code == MOUSE_LCLICK) {
    Mouse.set_buttons(1, 0, 0);
  }
  else if (layout->code == MOUSE_RCLICK) {
    Mouse.set_buttons(0, 0, 1);
  }
  else if (layout->code == KEY_RELEASE) {
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    Keyboard.releaseAll();
    touchActive = false;
  }
  else if (layout->code == KEY_ALT_TAB) {
    Keyboard.set_modifier(KEY_LEFT_ALT);
    Keyboard.send_now();
    Keyboard.set_key1(KEY_TAB);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  else if (layout->code == KEY_PLAY_PAUSE) {
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
    Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
  }
  else if (layout->code == KEY_MUTE) {
    Keyboard.press(KEY_MEDIA_MUTE);
    Keyboard.release(KEY_MEDIA_MUTE);
  }
  else if (layout->code == KEY_VOL_UP) {
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }
  else if (layout->code == KEY_VOL_DOWN) {
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  }
  else if (layout->code == KEY_VOL_UP_5) {
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }
  else if (layout->code == KEY_VOL_DOWN_5) {
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  }
  else if (layout->code == KEY_NEXT) {
    Keyboard.press(KEY_MEDIA_NEXT_TRACK);
    Keyboard.release(KEY_MEDIA_NEXT_TRACK);
  }
  else if (layout->code == KEY_PREV) {
    Keyboard.press(KEY_MEDIA_PREV_TRACK);
    Keyboard.release(KEY_MEDIA_PREV_TRACK);
  }
  else if (layout->code == KEY_RW) {
    Keyboard.press(KEY_MEDIA_REWIND);
    Keyboard.release(KEY_MEDIA_REWIND);
  }
  else if (layout->code == KEY_FF) {
    Keyboard.press(KEY_MEDIA_FAST_FORWARD);
    Keyboard.release(KEY_MEDIA_FAST_FORWARD);
  }
  else if (layout->code == KEY_REC) {
    Keyboard.press(KEY_MEDIA_RECORD);
    Keyboard.release(KEY_MEDIA_RECORD);
  }
  else if (layout->code == KEY_DEGREES) {
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press(KEYPAD_0);
    Keyboard.release(KEYPAD_0);
    Keyboard.press(KEYPAD_1);
    Keyboard.release(KEYPAD_1);
    Keyboard.press(KEYPAD_7);
    Keyboard.release(KEYPAD_7);
    Keyboard.press(KEYPAD_6);
    Keyboard.release(KEYPAD_6);
    Keyboard.release(KEY_RIGHT_ALT);
  }
  else if (layout->code == MACRON_E) {
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press(KEYPAD_PLUS);
    Keyboard.release(KEYPAD_PLUS);
    Keyboard.press(KEYPAD_0);
    Keyboard.release(KEYPAD_0);
    Keyboard.press(KEYPAD_1);
    Keyboard.release(KEYPAD_1);
    Keyboard.press(KEYPAD_1);
    Keyboard.release(KEYPAD_1);
    Keyboard.press(KEYPAD_3);
    Keyboard.release(KEYPAD_3);
    Keyboard.release(KEY_RIGHT_ALT);
  }
  else if (layout->code == EXCLAMATION) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_1);
    Keyboard.release(KEY_1);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_AT) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_2);
    Keyboard.release(KEY_2);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEY_HASH) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_3);
    Keyboard.release(KEY_3);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEY_DOLLAR) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_4);
    Keyboard.release(KEY_4);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEY_PERCENT) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_5);
    Keyboard.release(KEY_5);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_CARAT) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_6);
    Keyboard.release(KEY_6);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == AMPERSAND) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_7);
    Keyboard.release(KEY_7);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_ASTERISK) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_8);
    Keyboard.release(KEY_8);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == L_PARENTHESIS) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_9);
    Keyboard.release(KEY_9);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == R_PARENTHESIS) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_0);
    Keyboard.release(KEY_0);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == UNDERSCORE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_MINUS);
    Keyboard.release(KEY_MINUS);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_PIPE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_BACKSLASH);
    Keyboard.release(KEY_BACKSLASH);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_DBLQUOTE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_QUOTE);
    Keyboard.release(KEY_QUOTE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == LEFT_CHEVRON) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_COMMA);
    Keyboard.release(KEY_COMMA);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == RIGHT_CHEVRON) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_PERIOD);
    Keyboard.release(KEY_PERIOD);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == QUESTION_MARK) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_SLASH);
    Keyboard.release(KEY_SLASH);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_COLON) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_SEMICOLON);
    Keyboard.release(KEY_SEMICOLON);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == CURL_L_BRACE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_BRACE);
    Keyboard.release(KEY_LEFT_BRACE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == CURL_R_BRACE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_RIGHT_BRACE);
    Keyboard.release(KEY_RIGHT_BRACE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == SHIFT_TILDE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_TILDE);
    Keyboard.release(KEY_TILDE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_PLUS) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_EQUAL);
    Keyboard.release(KEY_EQUAL);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_REBOOT) {
    _reboot_Teensyduino_();
  } 
  else if (layout->code == KEY_SET0) {
    L_1 = 0;
    L_2 = 0;
    L_3 = 0;
    L_4 = 0;
    L_0CAPS = 0;
    L_MIRROR = 0;
    L_ALT = 0;
    L_ALT2 = 0;
  }
  else if (layout->code == LAYER_1) {
    L_1 = 1;
    L_check();
  }
  else if (layout->code == LAYER_2) {
    L_2 = 1;
    L_check();
  }
  else if (layout->code == LAYER_3) {
    L_3 = 1;
    L_check();
  }
  else if (layout->code == LAYER_4) {
    L_4 = 1;
    L_check();
  }
  else if (layout->code == LAYER_MIRROR) {
    L_MIRROR = 1;
    L_check();
  }
  else if (layout->code == LAYER_0CAPS) {
    L_0CAPS = !L_0CAPS;
    L_check();  
  }
  else if (layout->code == LAYER_ALT) {
    L_ALT = !L_ALT;
    L_ALT2 = 0;
    L_check();  
  }
  else if (layout->code == LAYER_ALT2) {
    L_ALT2 = !L_ALT2;
    L_ALT = 0;
    L_check();  
  }
  else if (layout->code == KEYSF13) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F13);
    Keyboard.release(KEY_F13);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF14) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F14);
    Keyboard.release(KEY_F14);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF15) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F15);
    Keyboard.release(KEY_F15);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF16) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F16);
    Keyboard.release(KEY_F16);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF17) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F17);
    Keyboard.release(KEY_F17);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF18) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F18);
    Keyboard.release(KEY_F18);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF19) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F19);
    Keyboard.release(KEY_F19);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF20) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F20);
    Keyboard.release(KEY_F20);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF21) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F21);
    Keyboard.release(KEY_F21);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF22) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F22);
    Keyboard.release(KEY_F22);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF23) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F23);
    Keyboard.release(KEY_F23);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEYSF24) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F24);
    Keyboard.release(KEY_F24);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else {
    Keyboard.press(layout->code);
  }
}
                                                         // All of the operations to be performed on key release
void keyReleased(Key* key, LayoutKey* layout) {
  if (layout->code == KEY_NULL) {
  }
  else if (layout->code == KEY_SET0) {
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_1) {
    L_1 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_2) {
    L_2 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_3) {
    L_3 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_4) {
    L_4 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_MIRROR) {
    L_MIRROR = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_0CAPS) {
    L_check();
  }
  else if (layout->code == LAYER_ALT) {
    L_check();
  }
  else if (layout->code == LAYER_ALT2) {
    L_check();
  }
  else if (layout->code == MOUSE_LCLICK) {
    Mouse.set_buttons(0, 0, 0);
  }
  else if (layout->code == MOUSE_RCLICK) {
    Mouse.set_buttons(0, 0, 0);
  }
  else {
    Keyboard.release(layout->code);
  }


}
