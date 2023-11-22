#ifndef LAYERS_H
#define LAYERS_H

#include "main.h"
#include "rgbleds.h"

typedef CRGB LedColor;
using LedColor = CRGB;
const LedColor Layer    = CRGB(0x00FFFF);
const LedColor Letter   = CRGB(0x8000FF);
const LedColor Number   = CRGB(0x0000FF);
      LedColor Numnav   = CRGB(0xAA00FF);
const LedColor Chara1   = CRGB(0x8000FF);
const LedColor Chara2   = CRGB(0xFF3300);
const LedColor Modifier = CRGB(0xFF0000);
      LedColor Capslock = CRGB(0xFF0000);
const LedColor FKeys1   = CRGB(0xFF2200);
const LedColor FKeys1b  = CRGB(0xFF0000);
const LedColor FKeys2   = CRGB(0x3300FF);
const LedColor FKeys2b  = CRGB(0xFF00FF);
const LedColor Special  = CRGB(0x00FF00);
      LedColor Nav      = CRGB(0x0000FF);
const LedColor LedAdj   = CRGB(0xFFFFFF);
const LedColor LEDoff   = CRGB(0x000000);

LayoutKey layout0[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_F1},      {KEY_F2},      {KEY_F3}, {KEY_F4}, {KEY_F5},   {KEY_F6},       {KEY_F7}, {KEY_F8},   {KEY_F9},       {KEY_F10},       {KEY_F11},       {KEY_F12},        {KEY_DELETE}},
  {{KEY_TILDE},     {KEY_1},       {KEY_2},       {KEY_3},  {KEY_4},  {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},         {KEY_MINUS},     {KEY_EQUAL},      {KEY_HOME},},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},       {KEY_E},  {KEY_R},  {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},         {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_END}},
  {{KEY_CAPS_LOCK}, {KEY_A},       {KEY_S},       {KEY_D},  {KEY_F},  {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON}, {KEY_QUOTE},     {KEY_ENTER},      {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},       {KEY_C},  {KEY_V},  {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},     {KEY_BACKSLASH}, {KEY_UP},         {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{LAYER_1},{LAYER_2},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{KEY_RIGHT_CTRL},{KEY_LEFT},      {KEY_DOWN},       {KEY_RIGHT}}
};
CRGB Leds0[rowsCount][columnsCount] = {
  {{Modifier},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1},{FKeys1b},{FKeys1b},{FKeys1b},{FKeys1b},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1},{Modifier}},
  {{Chara1},  {Number},  {Number},  {Number},{Number},{Number}, {Number}, {Number}, {Number}, {Number},  {Number},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter},{Letter}, {Letter}, {Letter}, {Letter}, {Letter},  {Letter},  {Chara1},{Chara1},{Modifier}},
  {{Capslock},{Letter},  {Letter},  {Letter},{Letter},{Letter}, {Letter}, {Letter}, {Letter}, {Letter},  {Chara1},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter},{Letter}, {Letter}, {Letter}, {Chara1}, {Chara1},  {Chara1},  {Chara1},{Nav},   {Modifier}},
  {{Modifier},{Modifier},{Modifier},{Layer}, {Layer}, {Chara1}, {Chara1}, {Layer},  {Layer},  {Modifier},{Modifier},{Nav},   {Nav},   {Nav}}
}; 




LayoutKey layout0alt[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_F1},      {KEY_F2},  {KEY_F3},  {KEY_F4},      {KEY_F5},   {KEY_F6},       {KEY_F7}, {KEY_F8},   {KEY_F9},       {KEY_F10},       {KEY_F11},       {KEY_F12},        {KEY_DELETE}},
  {{KEY_TILDE},     {KEY_1},       {KEY_2},   {KEY_3},   {KEY_4},       {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},         {KEY_MINUS},     {KEY_EQUAL},      {KEY_HOME},},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},   {KEY_E},   {KEY_R},       {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},         {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_END}},
  {{KEY_CAPS_LOCK}, {KEY_A},       {KEY_S},   {KEY_D},   {KEY_F},       {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON}, {KEY_QUOTE},     {KEY_ENTER},      {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},   {KEY_C},   {KEY_V},       {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},     {KEY_BACKSLASH}, {KEY_UP},         {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_NULL},{LAYER_1}, {KEY_LEFT_ALT},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{KEY_RIGHT_CTRL},{KEY_LEFT},      {KEY_DOWN},       {KEY_RIGHT}}
};
CRGB Leds0alt[rowsCount][columnsCount] = {
  {{Modifier},{FKeys1},  {FKeys1},{FKeys1},{FKeys1},  {FKeys1b},{FKeys1b},{FKeys1b},{FKeys1b},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1},{Modifier}},
  {{Chara1},  {Number},  {Number},{Number},{Number},  {Number},{Number},{Number},{Number},{Number},  {Number},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},{Letter},{Letter},  {Letter},{Letter},{Letter},{Letter},{Letter},  {Letter},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},{Letter},{Letter},  {Letter},{Letter},{Letter},{Letter},{Letter},  {Chara1},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},{Letter},{Letter},  {Letter},{Letter},{Letter},{Chara1},{Chara1},  {Chara1},  {Chara1},{Nav},   {Modifier}},
  {{Modifier},{Modifier},{LEDoff},   {Layer}, {Modifier},{Chara1},{Chara1},{Layer}, {Layer}, {Modifier},{Modifier},{Nav},   {Nav},   {Nav}}
}; 




LayoutKey layout0alt2[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_F1},      {KEY_F2},      {KEY_F3}, {KEY_F4},      {KEY_F5},   {KEY_F6},       {KEY_F7}, {KEY_F8},   {KEY_F9},       {KEY_F10},       {KEY_F11},       {KEY_F12},        {KEY_DELETE}},
  {{KEY_TILDE},     {KEY_1},       {KEY_2},       {KEY_3},  {KEY_4},       {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},         {KEY_MINUS},     {KEY_EQUAL},      {KEY_HOME},},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},       {KEY_E},  {KEY_R},       {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},         {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_END}},
  {{KEY_CAPS_LOCK}, {KEY_A},       {KEY_S},       {KEY_D},  {KEY_F},       {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON}, {KEY_QUOTE},     {KEY_ENTER},      {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},       {KEY_C},  {KEY_V},       {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},     {KEY_BACKSLASH}, {KEY_UP},         {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{LAYER_1},{MOUSE_RCLICK},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{KEY_RIGHT_CTRL},{KEY_LEFT},      {KEY_DOWN},       {KEY_RIGHT}}
};
CRGB Leds0alt2[rowsCount][columnsCount] = {
  {{Modifier},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1}, {FKeys1b},{FKeys1b},{FKeys1b},{FKeys1b},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1},{Modifier}},
  {{Chara1},  {Number},  {Number},  {Number},{Number}, {Number},{Number},{Number},{Number},{Number},  {Number},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter}, {Letter},{Letter},{Letter},{Letter},{Letter},  {Letter},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter}, {Letter},{Letter},{Letter},{Letter},{Letter},  {Chara1},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter}, {Letter},{Letter},{Letter},{Chara1},{Chara1},  {Chara1},  {Chara1},{Nav},   {Modifier}},
  {{Modifier},{Modifier},{Modifier},{Layer}, {Special},{Chara1},{Chara1},{Layer}, {Layer}, {Modifier},{Modifier},{Nav},   {Nav},   {Nav}}
}; 




LayoutKey layout0mirror[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_F1},      {KEY_F2},      {KEY_F3}, {KEY_F4}, {KEY_F5},   {KEY_F6},       {KEY_F7}, {KEY_F8},   {KEY_F9},       {KEY_F10},       {KEY_F11},       {KEY_F12},        {KEY_DELETE}},
  {{KEY_TILDE},     {KEY_1},       {KEY_2},       {KEY_3},  {KEY_4},  {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},         {KEY_MINUS},     {KEY_EQUAL},      {KEY_HOME},},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},       {KEY_E},  {KEY_R},  {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},         {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_END}},
  {{LAYER_MIRROR},  {KEY_A},       {KEY_S},       {KEY_D},  {KEY_F},  {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON}, {KEY_QUOTE},     {KEY_ENTER},      {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},       {KEY_C},  {KEY_V},  {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},     {KEY_BACKSLASH}, {KEY_UP},         {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{LAYER_1},{LAYER_2},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{KEY_RIGHT_CTRL},{KEY_LEFT},      {KEY_DOWN},       {KEY_RIGHT}}
};
CRGB Leds0mirror[rowsCount][columnsCount] = {
  {{Modifier},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1},{FKeys1b},{FKeys1b},{FKeys1b},{FKeys1b},{FKeys1},  {FKeys1},  {FKeys1},{FKeys1},{Modifier}},
  {{Chara1},  {Number},  {Number},  {Number},{Number},{Number},{Number},{Number},{Number},{Number},  {Number},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter},{Letter},{Letter},{Letter},{Letter},{Letter},  {Letter},  {Chara1},{Chara1},{Modifier}},
  {{Layer},   {Letter},  {Letter},  {Letter},{Letter},{Letter},{Letter},{Letter},{Letter},{Letter},  {Chara1},  {Chara1},{Chara1},{Modifier}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter},{Letter},{Letter},{Letter},{Chara1},{Chara1},  {Chara1},  {Chara1},{Nav},   {Modifier}},
  {{Modifier},{Modifier},{Modifier},{Layer}, {Layer}, {Chara1},{Chara1},{Layer}, {Layer}, {Modifier},{Modifier},{Nav},   {Nav},   {Nav}}
}; 




LayoutKey layoutMirror[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_F1},      {KEY_F2},      {KEY_F3},  {KEY_F4},        {KEY_F5},   {KEY_F6},       {KEY_F7},  {KEY_F8},  {KEY_F9},  {KEY_F10}, {KEY_F11}, {KEY_F12}, {KEY_DELETE}},
  {{KEY_0},         {KEY_9},       {KEY_8},       {KEY_7},   {KEY_6},         {KEY_5},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_P},         {KEY_O},       {KEY_I},       {KEY_U},   {KEY_Y},         {KEY_T},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{LAYER_MIRROR},  {KEY_L},       {KEY_K},       {KEY_J},   {KEY_H},         {KEY_G},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_LEFT_SHIFT},{KEY_PERIOD},  {KEY_COMMA},   {KEY_M},   {KEY_N},         {KEY_B},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{KEY_NULL},{KEY_LEFT_SHIFT},{KEY_SPACE},{KEY_BACKSPACE},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}}
};
CRGB LedsMirror[rowsCount][columnsCount] = {
  {{LEDoff},  {LEDoff},  {LEDoff},  {LEDoff},{LEDoff},  {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{Modifier}},
  {{Number},  {Number},  {Number},  {Number},{Number},  {Number},{Number},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Letter},  {Letter},  {Letter},  {Letter},{Letter},  {Letter},{Letter},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Layer},   {Letter},  {Letter},  {Letter},{Letter},  {Letter},{Letter},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Modifier},{Letter},  {Letter},  {Letter},{Letter},  {Letter},{Letter},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Modifier},{Modifier},{Modifier},{LEDoff},{Modifier},{Chara1},{Chara1},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}}
};




LayoutKey layout1[rowsCount][columnsCount] = {
  {{KEY_NULL},      {KEY_F13},     {KEY_F14},      {KEY_F15},     {KEY_F16}, {KEY_F17},  {KEY_F18},      {KEY_F19}, {KEY_F20}, {KEY_F21}, {KEY_F22}, {KEY_F23}, {KEY_F24},  {KEY_NULL}},
  {{KEYPAD_ASTERIX},{KEYPAD_SLASH},{KEYPAD_PLUS},  {KEYPAD_MINUS},{KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEYPAD_7},      {KEYPAD_8},    {KEYPAD_9},     {KEY_QUOTE},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEYPAD_4},      {KEYPAD_5},    {KEYPAD_6},     {KEY_DBLQUOTE},{KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_ENTER},{KEY_NULL}},
  {{KEYPAD_1},      {KEYPAD_2},    {KEYPAD_3},     {KEY_ENTER},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEYPAD_0},      {KEYPAD_0},    {KEYPAD_PERIOD},{LAYER_1},     {LAYER_2}, {KEY_SPACE},{KEY_BACKSPACE},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}}
};
CRGB Leds1[rowsCount][columnsCount] = {
  {{LEDoff},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{FKeys2b},{FKeys2b},{FKeys2b},{FKeys2b},   {FKeys2},   {FKeys2},   {FKeys2},   {FKeys2},   {LEDoff}},
  {{Chara2},{Chara2},{Chara2},{Chara2},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Number},{Number},{Number},{Chara2},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Number},{Number},{Number},{Chara2},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{Chara1},   {LEDoff}},
  {{Number},{Number},{Number},{Chara1},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{Number},{Number},{Chara2},{Layer}, {Layer}, {Chara1}, {Chara1}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}}
};




LayoutKey layout1_2[rowsCount][columnsCount] = {
  {{KEY_NULL},{KEYSF13}, {KEYSF14}, {KEYSF15}, {KEYSF16}, {KEYSF17},  {KEYSF18},      {KEYSF19}, {KEYSF20}, {KEYSF21}, {KEYSF22}, {KEYSF23}, {KEYSF24},  {KEY_NULL}},
  {{KEY_F1},  {KEY_F2},  {KEY_F3},  {KEY_F4},  {KEY_F5},  {KEY_F6},   {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_F7},  {KEY_F8},  {KEY_F9},  {KEY_F10}, {KEY_F11}, {KEY_F12},  {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_F13}, {KEY_F14}, {KEY_F15}, {KEY_F16}, {KEY_F17}, {KEY_F18},  {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_ENTER},{KEY_NULL}},
  {{KEY_F19}, {KEY_F20}, {KEY_F21}, {KEY_F22}, {KEY_F23}, {KEY_F24},  {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{LAYER_1}, {LAYER_2}, {KEY_SPACE},{KEY_BACKSPACE},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}}
};
CRGB Leds1_2[rowsCount][columnsCount] = {
  {{LEDoff}, {FKeys2}, {FKeys2},{FKeys2},{FKeys2}, {FKeys2b},{FKeys2b},{FKeys2b},{FKeys2b},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{LEDoff}},
  {{FKeys1}, {FKeys1}, {FKeys1},{FKeys1},{FKeys1b},{FKeys1b},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{FKeys1b},{FKeys1b},{FKeys1},{FKeys1},{FKeys1}, {FKeys1}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{FKeys2}, {FKeys2}, {FKeys2},{FKeys2},{FKeys2b},{FKeys2b},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{Chara1},{LEDoff}},
  {{FKeys2b},{FKeys2b},{FKeys2},{FKeys2},{FKeys2}, {FKeys2}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff}, {LEDoff}, {LEDoff},{Layer}, {Layer},  {Chara1}, {Chara1}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}}
};




LayoutKey layout2[rowsCount][columnsCount] = {
  {{KEY_NULL},      {KEY_F13},       {KEY_F14},      {KEY_F15},    {KEY_F16},     {KEY_F17},      {KEY_F18},      {KEY_F19},   {KEY_F20}, {KEY_F21},  {KEY_F22},    {KEY_F23}, {KEY_F24},  {KEY_NULL}},
  {{KEY_NULL},      {KEYPAD_ASTERIX},{KEYPAD_SLASH}, {KEYPAD_PLUS},{KEYPAD_MINUS},{KEY_NULL},     {KEY_NULL},     {KEY_NULL},  {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_ALT_TAB},   {KEYPAD_7},      {KEYPAD_8},     {KEYPAD_9},   {KEY_QUOTE},   {KEY_NULL},     {KEY_NULL},     {UNDERSCORE},{KEY_NULL},{KEY_NULL}, {KEY_PERCENT},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},      {KEYPAD_4},      {KEYPAD_5},     {KEYPAD_6},   {KEY_EQUAL},   {KEY_DEGREES},  {KEY_MINUS},    {KEY_NULL},  {KEY_NULL},{KEY_EQUAL},{KEY_NULL},   {KEY_NULL},{KEY_ENTER},{MOUSE_LCLICK}},
  {{KEY_LEFT_SHIFT},{KEYPAD_1},      {KEYPAD_2},     {KEYPAD_3},   {KEYPAD_ENTER},{KEY_BACKSLASH},{KEY_HASH},     {AMPERSAND}, {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_RELEASE},   {KEYPAD_0},      {KEYPAD_PERIOD},{LAYER_1},    {LAYER_2},     {KEY_DELETE},   {KEY_BACKSPACE},{LAYER_3},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL}}
};
CRGB Leds2[rowsCount][columnsCount] = {
  {{LEDoff},{FKeys2},    {FKeys2},    {FKeys2},    {FKeys2},    {FKeys2b},    {FKeys2b},    {FKeys2b},    {FKeys2b},   {FKeys2},    {FKeys2},    {FKeys2},   {FKeys2},   {LEDoff}},
  {{LEDoff},{Chara2},{Chara2},{Chara2},{Chara2},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff}},
  {{Special},{Number},   {Number},   {Number},   {Chara2},{LEDoff}, {LEDoff}, {Chara2},{LEDoff},{LEDoff}, {Chara2},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{Number},   {Number},   {Number},   {Chara2},{Chara2},{Chara2},{LEDoff}, {LEDoff},{Chara2},{LEDoff}, {LEDoff},{Chara1},   {Special}},
  {{Number},  {Number},   {Number},   {Number},   {Chara2},{Chara2},{Chara2},{Chara2},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff}},
  {{Special},{Number},   {Chara2},{Layer},  {Layer},  {Number},   {Chara1},    {Layer},  {LEDoff},{LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff}}
};




LayoutKey layout2_3[rowsCount][columnsCount] = {
  {{KEY_NULL},{KEY_F13},      {KEY_F14},     {KEY_F15},    {KEY_F16},     {KEY_F17},      {KEY_F18},      {KEY_F19},   {KEY_F20}, {KEY_F21},  {KEY_F22},    {KEY_F23}, {KEY_F24},  {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},     {KEY_NULL},    {KEY_NULL},   {KEY_NULL},    {KEY_NULL},     {KEY_NULL},     {KEY_NULL},  {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{QUESTION_MARK},{KEY_NULL},    {EXCLAMATION},{KEY_ASTERISK},{KEY_NULL},     {KEY_NULL},     {UNDERSCORE},{KEY_NULL},{KEY_NULL}, {KEY_PERCENT},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_AT},       {KEY_SLASH},   {KEY_DOLLAR}, {KEY_NULL},    {KEY_DEGREES},  {KEY_MINUS},    {KEY_NULL},  {KEY_NULL},{KEY_EQUAL},{KEY_NULL},   {KEY_NULL},{KEY_ENTER},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},     {KEY_ASTERISK},{KEY_CARAT},  {KEY_NULL},    {KEY_BACKSLASH},{KEY_HASH},     {AMPERSAND}, {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},     {KEY_NULL},    {KEY_NULL},   {LAYER_2},     {KEY_SPACE},    {KEY_BACKSPACE},{LAYER_3},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL}}
};
CRGB Leds2_3[rowsCount][columnsCount] = {
  {{LEDoff},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{FKeys2b},{FKeys2b}, {FKeys2b},{FKeys2b},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}, {LEDoff},  {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{Chara1},{LEDoff},{Chara1},{Chara1},{LEDoff}, {LEDoff},  {Chara1}, {LEDoff}, {LEDoff},{Chara1},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{Chara1},{Chara1},{Chara1},{LEDoff},{Chara1}, {Chara1},  {LEDoff}, {LEDoff}, {Chara1},{LEDoff},{LEDoff},{Chara1},{Special}},
  {{LEDoff},{LEDoff},{Chara1},{Chara1},{LEDoff},{Chara1}, {Chara1},  {Chara1}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{Layer}, {Layer}, {Chara1}, {Modifier},{Layer},  {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}}
};




LayoutKey layout3[rowsCount][columnsCount] = {
  {{KEY_NULL},{KEY_F13}, {KEY_F14}, {KEY_F15}, {KEY_F16}, {KEY_F17},       {KEY_F18},        {KEY_F19}, {KEY_F20}, {KEY_F21}, {KEY_F22}, {KEY_F23}, {KEY_F24},  {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{MACRON_E},{KEY_NULL},{CURL_L_BRACE},  {CURL_R_BRACE},   {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{L_PARENTHESIS}, {R_PARENTHESIS},  {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_ENTER},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{LEFT_CHEVRON},  {RIGHT_CHEVRON},  {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{LAYER_2}, {KEY_ENTER},     {KEY_DELETE},     {LAYER_3}, {LAYER_4}, {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL}}
};
CRGB Leds3[rowsCount][columnsCount] = {
  {{LEDoff},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{FKeys2b},{FKeys2b}, {FKeys2b},{FKeys2b},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{Chara2}, {Chara2},  {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{Letter},{LEDoff},{Chara2}, {Chara2},  {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{Chara2}, {Chara2},  {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{Chara1},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff},{Chara2}, {Chara2},  {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}},
  {{LEDoff},{LEDoff},{LEDoff},{LEDoff},{Layer}, {Chara1}, {Modifier},{Layer},  {Layer},  {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}}
};




LayoutKey layout3_4[rowsCount][columnsCount] = {
  {{KEY_NULL},{KEYSF13}, {KEYSF14}, {KEYSF15}, {KEYSF16}, {KEYSF17},  {KEYSF18},      {KEYSF19}, {KEYSF20}, {KEYSF21}, {KEYSF22}, {KEYSF23},      {KEYSF24},  {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},     {KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_7},{KEYPAD_8},{KEYPAD_9},     {KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_4},{KEYPAD_5},{KEYPAD_6},     {KEY_ENTER},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_1},{KEYPAD_2},{KEYPAD_3},     {KEY_NULL}, {KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3}, {LAYER_4}, {KEYPAD_0},{KEYPAD_0},{KEYPAD_PERIOD},{KEY_NULL}, {KEY_NULL}}
};
CRGB Leds3_4[rowsCount][columnsCount] = {
  {{LEDoff},{FKeys2b},{FKeys2b},{FKeys2b},{FKeys2b},{FKeys2},{FKeys2},{FKeys2},{FKeys2},{FKeys2b},{FKeys2b},{FKeys2b},{FKeys2b},{Modifier}},
  {{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}},
  {{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{Number}, {Number}, {Number}, {LEDoff}, {LEDoff}},
  {{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{Number}, {Number}, {Number}, {Chara1}, {LEDoff}},
  {{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{Number}, {Number}, {Number}, {LEDoff}, {LEDoff}},
  {{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff},{LEDoff},{LEDoff},{LEDoff},{Number}, {Number}, {Chara2}, {LEDoff}, {LEDoff}}
};




LayoutKey layout4[rowsCount][columnsCount] = {
  {{KEY_NULL},   {KEY_F13}, {KEY_F14}, {KEY_F15},   {KEY_F16},  {KEY_F17},  {KEY_F18},      {KEY_F19}, {KEY_F20}, {KEY_F21}, {KEY_F22},  {KEY_F23},      {KEY_F24},        {KEY_BACKSPACE}},
  {{LEDS_BR0},   {LEDS_BR1},{LEDS_BR2},{LEDS_BR3},  {LEDS_BR4}, {LEDS_BR5}, {LEDS_BR6},     {LEDS_BR7},{LEDS_BR8},{LEDS_BR9},{LEDS_BR10},{KEY_NULL},     {KEY_NULL},       {LEDS_INC}},
  {{KEY_NULL},   {KEY_NULL},{KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_7},{KEYPAD_8}, {KEYPAD_9},     {KEY_NULL},       {LEDS_DEC}},
  {{LAYER_0CAPS},{KEY_NULL},{KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_4},{KEYPAD_5}, {KEYPAD_6},     {KEY_ENTER},      {KEY_INSERT}},
  {{KEY_SET0},   {KEY_NULL},{KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_1},{KEYPAD_2}, {KEYPAD_3},     {KEY_PRINTSCREEN},{KEY_NUM_LOCK}},
  {{KEY_RELEASE},{KEY_NULL},{KEY_NULL},{LAYER_ALT2},{LAYER_ALT},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3}, {LAYER_4}, {KEYPAD_0},{KEYPAD_0}, {KEYPAD_PERIOD},{KEY_PAUSE},      {KEY_SCROLL_LOCK}}
};
CRGB Leds4[rowsCount][columnsCount] = {
  {{LEDoff}, {FKeys2},{FKeys2},{FKeys2}, {FKeys2}, {FKeys2b},{FKeys2b},{FKeys2b},{FKeys2b},{FKeys2}, {FKeys2},{FKeys2},{FKeys2}, {Chara1}},
  {{LedAdj}, {LedAdj},{LedAdj},{LedAdj}, {LedAdj}, {LedAdj}, {LedAdj}, {LedAdj}, {LedAdj}, {LedAdj}, {LedAdj},{LEDoff},{LEDoff}, {LedAdj}},
  {{LEDoff}, {LEDoff},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {Number}, {Number},{Number},{LEDoff}, {LedAdj}},
  {{Special},{LEDoff},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {Number}, {Number},{Number},{Chara1}, {Special}},
  {{Special},{LEDoff},{LEDoff},{LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {LEDoff}, {Number}, {Number},{Number},{Special},{Special}},
  {{Special},{LEDoff},{LEDoff},{Special},{Special},{Chara1}, {Chara1}, {Layer},  {Layer},  {Number}, {Number},{Chara2},{Special},{Special}}
};




#endif




/*
LayoutKey layout5[rowsCount][columnsCount] = {
  {{KEY_REBOOT},{KEY_GM1}, {KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},      {KEY_NULL},{KEY_PRINTSCREEN},{KEY_NUM_LOCK}},
  {{KEY_NULL},  {KEY_NULL},{KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},      {KEY_NULL},{KEY_PAUSE},      {KEY_SCROLL_LOCK}},
  {{KEY_NULL},  {KEY_NULL},{KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},      {KEY_NULL},{MOUSE_LCLICK},   {KEY_VOL_UP_5}},
  {{KEY_NULL},  {KEY_NULL},{KEY_NULL},{KEY_NULL},  {KEY_NULL}, {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_RW},  {KEY_FF},        {KEY_NULL},{KEY_VOL_UP},     {KEY_VOL_DOWN_5}},
  {{KEY_SET0},  {KEY_NULL},{KEY_NULL},{LAYER_ALT2},{LAYER_ALT},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_MUTE},{LAYER_5}, {KEY_PLAY_PAUSE},{KEY_PREV},{KEY_VOL_DOWN},   {KEY_NEXT}}
};
*/