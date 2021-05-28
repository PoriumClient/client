#include "Fullbright.h"

using namespace Pointers;



Fullbright::Fullbright() : Module::Module("Fullbright", "Graphics", 0x46) {

}

void Fullbright::onEnable() {
	auto d = (float*)Porium::GetPointerAddress(Porium::moduleBase + 0x03948848, { 0x28, 0x148, 0x18 });
	*d = 1000;
}

void Fullbright::onLoop() {
	/* 
	auto d = (float*)Porium::GetPointerAddress(Porium::moduleBase + 0x03948848, { 0x28, 0x148, 0x18 });
	if (toggled) {
		*d = 1000;
	}
	*d = 100;
	*/
}

void Fullbright::onDisable() {
	auto d = (float*)Porium::GetPointerAddress(Porium::moduleBase + 0x03948848, { 0x28, 0x148, 0x18 });
	*d = 1;
}