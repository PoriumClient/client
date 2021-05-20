#pragma once
#include <Windows.h>
#include <vector>



class Porium {
public:
	static uintptr_t GetPtrAddr(uintptr_t ptr, std::vector<uintptr_t> offsets); 

	static uintptr_t moduleBase;
};

