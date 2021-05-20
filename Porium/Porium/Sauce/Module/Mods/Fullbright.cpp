#include "Fullbright.h"

void Fullbright::onEnable() {
	*Pointers::Brightness = 1000;
}

void Fullbright::onDisable() {
	*Pointers::Brightness = 100;
}