#pragma once
#include "../SDK/Pointers.h"
#include "../Vendor.h"


class Module
{
public:
	Module(std::string name, std::string category, UINT64 keybind);
	UINT64 keybind;
	std::string name;
	std::string category;
	bool toggled = false;
	bool wasToggled = false;
	virtual void onLoop() {}
	virtual void onEnable() {}
	virtual void onDisable() {}
	virtual void onTick() {}
	virtual void onBaseTick();
	virtual void onKeyUpdate(int key) {}
};

