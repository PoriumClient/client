#pragma once

#include "../Vendor.h"
#include <MinHook.h>
#include "../Util/Utils.h"
#include "../Logger/Logger.h"
#include "../Module/ModuleMgr.h"

class Hooks {
public:
    static int KeyCallback(uint64_t WinKey, bool isDown);

    static DWORD __fastcall HookKeys();

    static void KeyPressed(UINT64 key);

    static void KeyReleased(UINT64 key);

    static void UninstallHooks();

    static void HookRenderer();
};

