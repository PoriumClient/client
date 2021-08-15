#include "Logger.h"

auto loggingPath = std::string(getenv("APPDATA") + std::string(
        "\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\\Porium.txt"));

void Logger::log(const std::string &log) {
    std::ofstream tooka;

    CloseHandle(
            CreateFileA(loggingPath.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr,
                        OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

    tooka.open(loggingPath.c_str(), std::ios_base::app);
    tooka << log << "\n" << std::endl;
    tooka.close();
}

[[maybe_unused]] void Logger::logStr(const std::string &str, UINT64 num) {
    std::stringstream strm;
    strm << str << ": " << std::hex << num;
    std::string result = strm.str();
    log(result);
}