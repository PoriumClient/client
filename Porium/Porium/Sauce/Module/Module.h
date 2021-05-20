#pragma once
#include "../SDK/Pointers.h"
class Module
{
public:
	bool toggled = false;
	virtual void onEnable();
	virtual void onDisable();
};

