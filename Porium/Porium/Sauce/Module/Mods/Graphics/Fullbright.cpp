#include "Fullbright.h"

Fullbright::Fullbright() : Module::Module("Fullbright", "Graphics", 0x46) {
}

void Fullbright::onEnable() {
	auto d = (float*)Porium::GetPointerAddress(Porium::moduleBase + 0x03F57C28, { 0x18, 0x150, 0x18 });
	*d = 1000;
}

void Fullbright::onLoop() {}

void Fullbright::onDisable() {
	auto d = (float*)Porium::GetPointerAddress(Porium::moduleBase + 0x03F57C28, { 0x18, 0x150, 0x18 });
	*d = 1;
}