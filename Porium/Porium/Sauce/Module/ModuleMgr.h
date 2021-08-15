#pragma once

#include "../Vendor.h"
#include "Module.h"

#include "Mods/Graphics/Fullbright.h"
#include "Mods/Dev/Uninject.h"

#include "../Hooks/Hooks.h"

class ModuleMgr {
    bool init = false;
public:
    static std::vector<Module *> getModules();

    static std::vector<std::string> getCategories();

    static void initMods();

    static void KeyHandler(ULONG key);

    static void tickMods();
};
