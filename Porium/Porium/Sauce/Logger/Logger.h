#pragma once
#include "../Vendor.h"
class Logger
{
public:
	static void log(std::string log);
	static void logStr(std::string str, UINT64 num);
};
