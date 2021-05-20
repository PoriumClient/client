#include <Windows.h>
#include "Sauce/Porium.h"

void Porium() {

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Porium, hModule, 0, 0);
        DisableThreadLibraryCalls(hModule);
        break;
    }
    return TRUE;
}

