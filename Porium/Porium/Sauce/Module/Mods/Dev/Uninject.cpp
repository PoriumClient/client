#include "Uninject.h"

Uninject::Uninject() : Module::Module("Uninject", "Dev", 0x55) {
	//U Key
}

void Uninject::onEnable() {
	Hooks::UninstallHooks();
	FreeLibraryAndExitThread((HMODULE)NULL, 0);
}