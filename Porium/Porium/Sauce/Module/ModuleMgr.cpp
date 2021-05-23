#include "ModuleMgr.h"

std::vector<Module*> Modules = std::vector<Module*>();
std::vector<std::string> Categories;


std::vector<Module*> ModuleMgr::getModules() {
	return Modules;
}

std::vector<std::string> ModuleMgr::getCategories() {
	return Categories;
}

void ModuleMgr::initMods() {
	Modules.push_back(new Fullbright());

	for (UINT32 i = 0; i < Modules.size(); i++) {
		if (find(Categories.begin(), Categories.end(), Modules[i]->category) == Categories.end()) {
			Categories.push_back(Modules[i]->category);
		}
	}
}

void ModuleMgr::tickMods() {
	for (UINT i = 0; i < Modules.size(); i++) {
		Modules[i]->onLoop();
	}
}