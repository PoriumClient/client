#pragma once
#include <CasualLibrary.hpp>

#pragma comment(lib,"CasualLibrary.lib")

class Pointers {
public:
	static Address clientAddr;
	static Address Brightness;
};

Address Pointers::clientAddr = Memory::Internal::getModule("Minecraft.Windows.exe");

Address Pointers::Brightness = Memory::Internal::getAddress(clientAddr + 0x03F57C28, { 0x18, 0x150, 0x18 });