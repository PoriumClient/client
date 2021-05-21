#pragma once
#include "../../Vendor.h"
#include "../Module.h"
#include "../../SDK/Pointers.h"	

class Fullbright : public Module 
{
public:
	Fullbright();
	void onEnable() override;
	void onDisable() override;
};

