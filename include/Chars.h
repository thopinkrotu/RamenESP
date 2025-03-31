#ifndef CHARS_H
#define CHARS_H

#include <Arduino.h>

namespace Chars
{
	byte player[] = {
		B01110,
		B01110,
		B00100,
		B01110,
		B10101,
		B00100,
		B01010,
		B10001};

	byte enemy[] = {
		B00000,
		B10001,
		B01010,
		B00100,
		B01010,
		B10001,
		B00000,
		B00000};

	byte star[] = {
		B00000,
		B00100,
		B01110,
		B11111,
		B01110,
		B00100,
		B00000,
		B00000};

	byte arrow_left[] = {
		B00000,
		B00100,
		B01100,
		B11111,
		B11111,
		B01100,
		B00100,
		B00000};

	byte arrow_right[] = {
		B00000,
		B00100,
		B00110,
		B11111,
		B11111,
		B00110,
		B00100,
		B00000};

	int char_count = 5;
	byte *chars[] = {
		arrow_left,
		arrow_right,
		player,
		enemy,
		star};
};

#endif