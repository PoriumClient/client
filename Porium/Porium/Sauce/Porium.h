#pragma once
#include <Windows.h>
#include <vector>



class Porium {
public:
    static uintptr_t GetPointerAddress(uintptr_t ptr, std::vector<uintptr_t> offsets) {
        uintptr_t addr = ptr;
        for (int i = 0; i < offsets.size(); ++i) {
            addr = *(uintptr_t*)addr;
            addr += offsets[i];
        }
        return addr;
    }
    static uintptr_t moduleBase;
};

