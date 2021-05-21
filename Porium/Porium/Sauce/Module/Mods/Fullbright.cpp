#include "Fullbright.h"

Fullbright::Fullbright() : Module::Module("Flight", "Player") {

}

void Fullbright::onEnable() {
	*Pointers::Brightness = 1000;
}

void Fullbright::onDisable() {
	*Pointers::Brightness = 100;
}