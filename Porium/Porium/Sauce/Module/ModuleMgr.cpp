#include "ModuleMgr.h"

std::vector<Module*> Modules = std::vector<Module*>();
std::vector<std::string> Categories = std::vector < std::string > ();


std::vector<Module*> ModuleMgr::getModules() {
	return Modules;
}

std::vector<std::string> ModuleMgr::getCategories() {
	return Categories;
}

void ModuleMgr::initMods() {
	this->modList.push_back(std::shared_ptr<Module>(new Fullbright()));

	init = true;
}