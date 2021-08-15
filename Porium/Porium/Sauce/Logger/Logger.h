#pragma once

#include "../Vendor.h"

class Logger {
public:
    static void log(const std::string &log);

    [[maybe_unused]] static void logStr(const std::string &str, UINT64 num);
};
