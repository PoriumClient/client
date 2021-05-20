#include "Porium.h"

uintptr_t Porium::GetPtrAddr(uintptr_t ptr, std::vector<uintptr_t> offsets){
uintptr_t addr = ptr;
for (int i = 0; i < offsets.size(); ++i) {
	addr = *(uintptr_t*)addr;
	addr += offsets[i];
}
return addr;
}

uintptr_t Porium::moduleBase = (uintptr_t)GetModuleHandle(nullptr);