#pragma once
#include "../Vendor.h"
#include "Module.h"

#include "Mods/Fullbright.h"

class ModuleMgr {
	std::vector<std::shared_ptr<Module>> modList;
	bool init = false;
public:
	static std::vector<Module*> getModules();
	static std::vector<std::string> getCategories();

	void initMods();
	void tickMods();

	void tickOnRender();
};
