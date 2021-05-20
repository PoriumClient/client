#pragma once
class Module
{
public:
	bool toggled = false;
	virtual void onEnable();
	virtual void onDisable();
};

