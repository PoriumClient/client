#include "Fullbright.h"
#include "../../../SDK/Pointers.h"


Fullbright::Fullbright() : Module::Module("Fullbright", "Graphics", 0x46) {
}

void Fullbright::onEnable() {
    Memory::Internal::write<float>(Pointers::Brightness, 1000);
}

void Fullbright::onLoop() {}

void Fullbright::onDisable() {
    Memory::Internal::write<float>(Pointers::Brightness, 1);
}