#pragma once
#include "../SDK/Pointers.h"
#include "../Vendor.h"

class Module
{
public:
	Module(std::string name, std::string category);
	std::string name;
	std::string category;
	bool toggled = false;
	virtual void onEnable();
	virtual void onDisable();
};

