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
	virtual void onLoop();
	bool toggled = false;
	bool wasToggled = false;
	virtual void onEnable();
	virtual void onDisable();
	virtual void onTick() {}

};

