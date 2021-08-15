#pragma once

#include <Windows.h>
#include <vector>

class Porium {
public:
    static uintptr_t GetPointerAddress(uintptr_t ptr, const std::vector<uintptr_t> &offsets) {
        uintptr_t addr = ptr;
        for (unsigned long long offset : offsets) {
            addr = *(uintptr_t *) addr;
            addr += offset;
        }
        return addr;
    }

    [[maybe_unused]] static uintptr_t moduleBase;

    static ULONG thisModule() {
        return (ULONG) GetModuleHandleA("Porium.dll");
    }
};
