#include "Module.h"
#include "../Hooks/Hooks.h"

Module::Module(std::string name, std::string category, UINT64 keybind) {
	this->name = name;
	this->category = category;
	this->keybind = keybind;
}

void Module::onEnable() {

}

void Module::onDisable() {

}

void Module::onLoop() {
	if (wasToggled != toggled) {
		if (toggled) {
			onEnable();
		}
		else {
			onDisable();
		}
		wasToggled = toggled;
	}
	if (toggled) {
		onTick();
	}
	if (Hooks::KeyState(keybind)) {
		toggled = !toggled;
		Sleep(10);
	}
}

