#include <Windows.h>
#include "Sauce/Module/ModuleMgr.h"
#include "Sauce/Hooks/Hooks.h"
#include <MinHook.h>

[[noreturn]] void Tooka()
{
	if (MH_Initialize() == MH_OK) {
		ModuleMgr::initMods();
		Hooks::HookKeys();
		while (true) {
			ModuleMgr::tickMods();
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Tooka, hModule, 0, 0);
		break;
	}
	return TRUE;
}