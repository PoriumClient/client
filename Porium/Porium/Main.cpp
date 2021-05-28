#include <Windows.h>
#include "Sauce/Logger/Logger.h"
#include "Sauce/Porium.h"
#include "Sauce/Module/ModuleMgr.h"
#include "Sauce/Hooks/Hooks.h"
#include <MinHook.h>

void Tooka()
{
    if (MH_Initialize() == MH_OK) {
       ModuleMgr::initMods();
       Hooks::HookKeys();
       while (1) {
           ModuleMgr::tickMods();
       }
    }
}


BOOL APIENTRY DllMain( HMODULE hModule,
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

