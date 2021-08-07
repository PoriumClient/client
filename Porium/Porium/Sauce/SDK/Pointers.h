#pragma once
#include <CasualLibrary.hpp>

#pragma comment(lib,"CasualLibrary.lib")

class Pointers {
public:
	static Address clientAddr;
	static Address Brightness;
};

Address Pointers::clientAddr = Memory::Internal::getModule("Minecraft.Windows.exe");

Address Pointers::Brightness = Memory::Internal::getAddress(clientAddr + 0x03F594F8, { 0x10, 0xFC8, 0x8, 0xF8, 0x170, 0x140, 0x18 });