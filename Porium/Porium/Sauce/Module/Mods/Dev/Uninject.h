#pragma once

#include "../../Module.h"
#include "../../../Hooks/Hooks.h"
#include "../../../Porium.h"

class Uninject : public Module {
public:
    Uninject();

    void onEnable() override;
};
