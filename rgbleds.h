#ifndef RGBLEDS_H
#define RGBLEDS_H

#include <WS2812Serial.h>
#define USE_WS2812SERIAL
#include <FastLED.h>

#include "main.h"
#include "rgbleds.h"
#include "layers.h"


class rgbleds {
  public:
    static void setup();
    static void loop();
};

#define NUM_LEDS 84
#define DATA_PIN 1

bool isNumOn(){
  return (keyboard_leds & 1) == 1;
}

bool isCapsOn(){
  return (keyboard_leds & 2) == 2;
}

bool isScrollOn(){
  return (keyboard_leds & 4) == 4;
}

int brightness = 9;
const int brt0 = 0;
const int brt1 = 1;
const int brt2 = 2;
const int brt3 = 3;
const int brt4 = 4;
const int brt5 = 6;
const int brt6 = 9;
const int brt7 = 12;
const int brt8 = 16;
const int brt9 = 24;
const int brt10 = 32;

CRGB leds[NUM_LEDS];

int XYMatrix[rowsCount][columnsCount] = {
  {13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
  {14,15,16,17,18,19,20,21,22,23,24,25,26,27},
  {41,40,39,38,37,36,35,34,33,32,31,30,29,28},
  {42,43,44,45,46,47,48,49,50,51,52,53,54,55},
  {69,68,67,66,65,64,63,62,61,60,59,58,57,56},
  {70,71,72,73,74,75,76,77,78,79,80,83,81,82}
};

void leds0() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds0[row][col];
    }
  }
  FastLED.show();
}
void leds0mirror() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds0mirror[row][col];
    }
  }
  FastLED.show();
}
void leds0alt() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds0alt[row][col];
    }
  }
  FastLED.show();
}
void leds0alt2() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds0alt2[row][col];
    }
  }
  FastLED.show();
}
void ledsMirror() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = LedsMirror[row][col];
    }
  }
  FastLED.show();
};
void leds1() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds1[row][col];
    }
  }
  FastLED.show();
};
void leds1_2() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds1_2[row][col];
    }
  }
  FastLED.show();
};
void leds2() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds2[row][col];
    }
  }
  FastLED.show();
};
void leds2_3() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds2_3[row][col];
    }
  }
  FastLED.show();
};
void leds3() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds3[row][col];
    }
  }
  FastLED.show();
};
void leds3_4() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds3_4[row][col];
    }
  }
  FastLED.show();
};
void leds4() {
  for (int row = 0; row < rowsCount; row++) {
    for (int col = 0; col < columnsCount; col++) {
      int ledIndex = XYMatrix[row][col];
      leds[ledIndex] = Leds4[row][col];
    }
  }
  FastLED.show();
};


void capscheck() {
  if ((keyboard_leds & 2) == 2) {
    leds[42] = CRGB::Yellow;
    FastLED.show();
  }
}

/*
void scrollcheck() {
  if ((keyboard_leds & 4) == 4) {
    leds[42] = CRGB::Green;
    FastLED.show();
  }
}
void numcheck() {
  if ((keyboard_leds & 1) == 1) {
    leds[42] = CRGB::Yellow;
    FastLED.show();
  }
}
*/

void rgbleds::setup() {

  LEDS.addLeds<WS2812SERIAL, DATA_PIN, BRG>(leds, NUM_LEDS);
  LEDS.setBrightness(brightness);
  leds0();
  
}



void rgbleds::loop() {




}

#endif







