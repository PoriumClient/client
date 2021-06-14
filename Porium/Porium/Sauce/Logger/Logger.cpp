#include "Logger.h"

std::string loggingPath = std::string(getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\\Porium.txt"));

void Logger::log(std::string log) {
	std::ofstream tooka;

	CloseHandle(CreateFileA(loggingPath.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

	tooka.open(loggingPath.c_str(), std::ios_base::app);
	tooka << log << "\n" << std::endl;
	tooka.close();
	return;
}

void Logger::logStr(std::string str, UINT64 num) {
	std::stringstream strm;
	strm << str << ": " << std::hex << num;
	std::string result = strm.str();
	log(result);
}