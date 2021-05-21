#pragma once
#include "../SDK/Pointers.h"
#include "../Vendor.h"

class Module
{
public:
	std::string category;
	bool toggled = false;
	virtual void onEnable();
	virtual void onDisable();
};

