#include "Hooks.h"

typedef void(WINAPI* _KeyPress)(uint64_t WinKey, bool isDown);
typedef int(WINAPI* KeyPressed)(UINT64 key, bool pressed);
_KeyPress KeyPress;
KeyPressed original;

void Hooks::HookKeys() {

	//	if (MH_CreateHook((void*)KeySig, &KeyCallback, reinterpret_cast<LPVOID*>(&KeyPress)) == MH_OK) {
	//		MH_EnableHook((void*)KeySig);
	//	}
}