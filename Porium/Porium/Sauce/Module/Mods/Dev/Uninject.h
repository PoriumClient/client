#pragma once
#include "../../Module.h"
#include "../../../Vendor.h"
#include "../../../Hooks/Hooks.h"

class Uninject : public Module
{
public:
	Uninject();
	void onEnable() override;
};
