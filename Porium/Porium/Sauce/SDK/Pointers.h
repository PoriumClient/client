#pragma once
#include "../Porium.h"

class Pointers {
public:
	static inline float* Brightness = (float*)Porium::GetPtrAddr(Porium::moduleBase + 0x03948840, { 0x10, 0xF0, 0x8, 0xF8, 0x170, 0x138, 0x18 });
};


