#include <Chars.h>

byte Chars::player[] = {
    B01110,
    B01110,
    B00100,
    B01110,
    B10101,
    B00100,
    B01010,
    B10001};

byte Chars::enemy[] = {
    B00000,
    B10001,
    B01010,
    B00100,
    B01010,
    B10001,
    B00000,
    B00000};

byte Chars::star[] = {
    B00000,
    B00100,
    B01110,
    B11111,
    B01110,
    B00100,
    B00000,
    B00000};

byte Chars::arrow_left[] = {
    B00000,
    B00100,
    B01100,
    B11111,
    B11111,
    B01100,
    B00100,
    B00000};

byte Chars::arrow_right[] = {
    B00000,
    B00100,
    B00110,
    B11111,
    B11111,
    B00110,
    B00100,
    B00000};

byte Chars::full_block[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111};

byte *Chars::chars[2] = {player, full_block};
