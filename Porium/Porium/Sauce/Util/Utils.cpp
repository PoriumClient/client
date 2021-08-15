#pragma warning(disable : 4996)

#include "Utils.h"

HMODULE Utils::hModule = NULL;
GameMode *Utils::currentGM = nullptr;
std::map<uint64_t, bool> Utils::keyMapping;

float Utils::distanceBetweenVec3(Vector3 VecA, Vector3 VecB) {
    float dX = VecA.x - VecB.x;
    float dY = VecA.y - VecB.y;
    float dZ = VecA.z - VecB.z;
    return sqrt(dX * dX + dY * dY + dZ * dZ);
}

bool Utils::isInteger(std::string str) {
    bool rtnVal = false;
    int count = 0;

    for (int I = 0; I < str.size(); I++) {
        if (I == 0) {
            if (std::isdigit(str[I])) {
                count++;
            } else {
                if (str.at(I) == '-' && str.size() > 1) count++;
            }
        } else {
            if (std::isdigit(str[I])) {
                count++;
            } else if (str.at(I) == '.') count++;
        }
    }

    if (count == str.size()) rtnVal = true;

    return rtnVal;
}

bool Utils::isFloatNegative(float value) {
    return (float) (value < 0.0f);
}

bool Utils::isIntNegative(int value) {
    return (int) (value < 0);
}

bool Utils::stringIntToBool(std::string str) {
    if (str.length() > 0) {
        return str[0] == '1';
    } else {
        return false;
    }
}

bool Utils::fileExists(const std::string &filePath) {
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

uintptr_t Utils::FindSignatureModule(const char *szModule, const char *szSignature) {
    const char *pattern = szSignature;
    uintptr_t firstMatch = 0;
    static const uintptr_t rangeStart = (uintptr_t) GetModuleHandleA(szModule);
    static MODULEINFO miModInfo;
    static bool init = false;
    if (!init) {
        init = true;
        GetModuleInformation(GetCurrentProcess(), (HMODULE) rangeStart, &miModInfo, sizeof(MODULEINFO));
    }
    static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

    BYTE patByte = GET_BYTE(pattern);
    const char *oldPat = pattern;

    for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++) {
        if (!*pattern)
            return firstMatch;

        while (*(PBYTE) pattern == ' ')
            pattern++;

        if (!*pattern)
            return firstMatch;

        if (oldPat != pattern) {
            oldPat = pattern;
            if (*(PBYTE) pattern != '\?')
                patByte = GET_BYTE(pattern);
        }

        if (*(PBYTE) pattern == '\?' || *(BYTE *) pCur == patByte) {
            if (!firstMatch)
                firstMatch = pCur;

            if (!pattern[2])
                return firstMatch;

            pattern += 2;
        } else {
            pattern = szSignature;
            firstMatch = 0;
        }
    }
#ifdef _DEBUG
    const char *sig = szSignature;
#endif
    return 0u;
}

void Utils::Patch(BYTE *dst, BYTE *src, unsigned int size) {
    DWORD oldprotect;
    VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

    memcpy(dst, src, size);
    VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void Utils::Nop(BYTE *dst, unsigned int size) {
    DWORD oldprotect;
    VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
    memset(dst, 0x90, size);
    VirtualProtect(dst, size, oldprotect, &oldprotect);
}

std::vector<std::string> Utils::smallestToBiggestStringVec(std::vector<std::string> strArr) {
    for (int I = 0; I < strArr.size(); I++) {
        std::string temp = strArr[I];

        int J = I - 1;
        while (J >= 0 && temp.length() < strArr[J].length()) {
            strArr[J + 1] = strArr[J];
            J--;
        }
        strArr[J + 1] = temp;
    }
    return strArr;
}

std::string Utils::strToLower(std::string inputStr) {
    std::string returnString = std::string();

    for (int I = 0; I < inputStr.size(); I++) {
        returnString.push_back(std::tolower(inputStr.at(I)));
    }

    return returnString;
}