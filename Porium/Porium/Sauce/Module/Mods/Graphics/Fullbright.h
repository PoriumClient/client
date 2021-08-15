#pragma once

#include "../../Module.h"
#include "../../../Vendor.h"


class Fullbright : public Module {
public:
    Fullbright();

    void onEnable() override;

    void onDisable() override;

    void onLoop() override;
};
