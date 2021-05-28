#include "Hooks.h"

typedef int(WINAPI* KeyPressed)(UINT64 key, bool pressed);
KeyPressed original;

std::map<UINT64, bool> keyState;

bool Hooks::KeyState(UINT64 key) {return keyState[key];}

void Hooks::KeyPressed(UINT64 key) { keyState[key] = true; ModuleMgr::KeyHandler(key); Logger::log("keypress: " + key); }

void Hooks::KeyReleased(UINT64 key) {keyState[key] = false;}


int Hooks::KeyCallback(UINT64 WinKey, bool isDown) {
	if (isDown) {
		Hooks::KeyPressed(WinKey);
	}
	else {
		KeyReleased(WinKey);
	}
	return original(WinKey, isDown);
}

DWORD __fastcall Hooks::HookKeys(){
    uintptr_t KeySig = Utils::FindSignature("89 ?? ?? ?? 57 48 83 ?? ?? 8B 05 ?? ?? ?? ?? 8B");
		Logger::log("Minhook initialized.");
		if (MH_CreateHook((void*)KeySig, &KeyCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
			if (MH_EnableHook((void*)KeySig) == MH_OK) {
				Logger::log("EXPANDO IS MY HOMIE!");
			}
			else {
				Logger::log("Failed to enable KeyHook");
			}
		}
		else {
			Logger::log("Failed to create KeyHook");
		}
    return 0;
}
