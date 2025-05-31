#ifndef CHARS_H
#define CHARS_H

#include <Arduino.h>

namespace Chars
{
	extern byte player[];
	extern byte enemy[];
	extern byte star[];
	extern byte full_block[];

	extern byte arrow_left[];
	extern byte arrow_right[];

	extern byte *chars[2];
};

#endif