#pragma once
#include <string>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <cctype>
#include <algorithm>
#include <map>
#include <Psapi.h>
#define PI 3.14159265359
#define FindSignature(szSignature) Utils::FindSignatureModule("Minecraft.Windows.exe", szSignature)
enum class PacketType {
	Movement,
	PlayerAuthInput,
	Text,
	ActorFall,
	Unknown
};

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

static constexpr float DEG_RAD2 = PI / 360.0f;
static constexpr float DEG_RAD = 180.0f / PI;
static constexpr float RAD_DEG = PI / 180.f;

static const char* const KeyNames[] = {
	"Unknown",
	"VK_LBUTTON",
	"VK_RBUTTON",
	"VK_CANCEL",
	"VK_MBUTTON",
	"VK_XBUTTON1",
	"VK_XBUTTON2",
	"Unknown",
	"VK_BACK",
	"TAB",
	"Unknown",
	"Unknown",
	"VK_CLEAR",
	"VK_RETURN",
	"Unknown",
	"Unknown",
	"Shift",
	"CTRL",
	"VK_MENU",
	"VK_PAUSE",
	"VK_CAPITAL",
	"VK_KANA",
	"Unknown",
	"VK_JUNJA",
	"VK_FINAL",
	"VK_KANJI",
	"Unknown",
	"VK_ESCAPE",
	"VK_CONVERT",
	"VK_NONCONVERT",
	"VK_ACCEPT",
	"VK_MODECHANGE",
	"VK_SPACE",
	"VK_PRIOR",
	"VK_NEXT",
	"VK_END",
	"VK_HOME",
	"VK_LEFT",
	"VK_UP",
	"VK_RIGHT",
	"VK_DOWN",
	"VK_SELECT",
	"VK_PRINT",
	"VK_EXECUTE",
	"VK_SNAPSHOT",
	"INSERT",
	"DELETE",
	"VK_HELP",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"VK_LWIN",
	"VK_RWIN",
	"VK_APPS",
	"Unknown",
	"VK_SLEEP",
	"NUMPAD0",
	"NUMPAD1",
	"NUMPAD2",
	"NUMPAD3",
	"NUMPAD4",
	"NUMPAD5",
	"NUMPAD6",
	"NUMPAD7",
	"NUMPAD8",
	"NUMPAD9",
	"VK_MULTIPLY",
	"VK_ADD",
	"VK_SEPARATOR",
	"VK_SUBTRACT",
	"VK_DECIMAL",
	"VK_DIVIDE",
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12",
	"VK_F13",
	"VK_F14",
	"VK_F15",
	"VK_F16",
	"VK_F17",
	"VK_F18",
	"VK_F19",
	"VK_F20",
	"VK_F21",
	"VK_F22",
	"VK_F23",
	"VK_F24",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"VK_NUMLOCK",
	"VK_SCROLL",
	"VK_OEM_NEC_EQUAL",
	"VK_OEM_FJ_MASSHOU",
	"VK_OEM_FJ_TOUROKU",
	"VK_OEM_FJ_LOYA",
	"VK_OEM_FJ_ROYA",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"Unknown",
	"LeftShift",
	"RightShift",
	"VK_LCONTROL",
	"VK_RCONTROL",
	"VK_LMENU",
	"VK_RMENU",
	"Browser Back",
	"Browser Forward",
	"Browser Refresh",
	"Browser Stop",
	"Browser Search",
	"Browser Favourites",
	"Browser Home",
	"Volume Mute",
	"Volume Down",
	"Volume Up",
	"Media_Next",
	"Media_Prev",
	"Media_Stop",
	"Media_Pause",
	"Mail",
	"Media",
	"App1",
	"App2",
	"Unknown",
	"Unknown",
	"OEM_1",
	"PLUS",
	"COMMA",
	"MINUS",
	"DOT",
	"OEM_2",
	"OEM_3" };

struct Vector2 {
	union {
		struct {
			float x, y;
		};
		float arr[2];
	};
	Vector2() { x = y = 0; };
	Vector2(float x, float y) { this->x = x, this->y = y; };

	bool operator == (Vector2 compareVec) { return compareVec.x == x && compareVec.y == y; };
	bool operator != (Vector2 compareVec) { return compareVec.x != x || compareVec.y != y; };

	Vector2 sub(Vector2 subVec) {
		return Vector2(subVec.x - x, subVec.y - y);
	};

	Vector2 sub(float f) {
		return Vector2(f - x, y - f);
	};

	Vector2 add(Vector2 addVec) {
		return Vector2(x + addVec.x, y + addVec.y);
	};

	Vector2 add(float f) {
		return Vector2(x + f, y + f);
	};

	Vector2 mult(Vector2 multVec) {
		return Vector2(x * multVec.x, y * multVec.y);
	};

	Vector2 mult(float f) {
		return Vector2(x * f, y * f);
	};

	Vector2 div(Vector2 divVec) {
		return Vector2(x / divVec.x, y / divVec.y);
	};

	Vector2 div(float f) {
		return Vector2(x / f, y / f);
	};

	float magnitexy() const { return sqrtf(x * x + y * y); };
};

struct Vector3 {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};
	Vector3() { x = y = z = 0; };
	Vector3(float x, float y, float z) { this->x = x, this->y = y, this->z = z; };

	bool operator == (Vector3 compareVec) { return compareVec.x == x && compareVec.y == y && compareVec.z == z; };
	bool operator != (Vector3 compareVec) { return compareVec.x != x || compareVec.y != y || compareVec.z != z; };

	Vector3 sub(Vector3 subVec) {
		return Vector3(x - subVec.x, y - subVec.y, z - subVec.z);
	};

	Vector3 sub(float f) {
		return Vector3(x - f, y - f, z - f);
	};

	Vector3 add(Vector3 addVec) {
		return Vector3(x + addVec.x, y + addVec.y, z + addVec.z);
	};

	Vector3 add(float f) {
		return Vector3(x + f, y + f, z + f);
	};

	Vector3 div(Vector3 divVec) {
		return Vector3(x / divVec.x, y / divVec.y, z / divVec.z);
	};

	Vector3 div(float f) {
		return Vector3(x / f, y / f, z / f);
	};

	Vector3 mult(Vector3 multVec) {
		return Vector3(x * multVec.x, y * multVec.y, z * multVec.z);
	};

	Vector3 mult(float f) {
		return Vector3(x * f, y * f, z * f);
	};

	Vector3 floor() { return Vector3(floorf(x), floorf(y), floorf(z)); };

	float squaredlen() const { return x * x + y * y + z * z; };
	float squaredxzlen() const { return x * x + z * z; };

	float magnitudexy() const { return sqrtf(x * x + y * y); };
	float magnitudexz() const { return sqrtf(x * x + z * z); };
	float magnitude() const { return sqrtf(squaredlen()); };

	Vector3 normalize() {
		return div(magnitude());
	};
};

struct Vector3i {
	union {
		struct {
			int x, y, z;
		};
		int arr[3];
	};

	Vector3i() { x = y = z = 0; };
	Vector3i(int x, int y, int z) { this->x = x, this->y = y, this->z = z; };

	Vector3i(Vector3i const& cloneVec) { this->x = cloneVec.x, this->y = cloneVec.y, this->z = cloneVec.z; };
	Vector3i(Vector3 const& tempVec) { this->x = (int)tempVec.x, this->y = (int)tempVec.y, this->z = (int)tempVec.z; };

	Vector3i sub(Vector3i const& newVec) {
		return Vector3i(x - newVec.x, y - newVec.y, z - newVec.z);
	};
};

struct Vector4 {
	union {
		struct {
			float x, y, z, w;
		};
		float arr[4];
	};
	Vector4() { x = y = z = w = 0; }
	Vector4(float x = 0, float y = 0, float z = 0, float w = 0) {
		this->x = x, this->y = y, this->z = z, this->w = w;
	}

	bool operator == (Vector4 v) { return v.x == x && v.y == y && v.z == z && v.w == w; };
	bool operator != (Vector4 v) { return v.x != x || v.y != y || v.z != z || v.w != w; };
};

struct Color : Vector4 {
	bool deletable;
	Color(float x, float y, float z, float w, bool deletable) : Vector4::Vector4(x, y, z, w) {
		this->deletable = deletable;
	}
	Color(float x, float y, float z, float w) : Vector4::Vector4(x, y, z, w) {
		this->deletable = false;
	}
};

class Utils {
public:

	static std::string strToLower(std::string inputStr);
	static bool fileExists(const std::string& filePath);
	static bool stringIntToBool(std::string str);

	static uintptr_t FindSignatureModule(const char* szModule, const char* szSignature);
	static void Patch(BYTE* dst, BYTE* src, unsigned int size);
	static void Nop(BYTE* dst, unsigned int size);
	static std::vector<std::string> smallestToBiggestStringVec(std::vector<std::string> strArr);
	static bool isInteger(std::string str);
	static bool isFloatNegative(float value);
	static bool isIntNegative(int value);
	static float distanceBetweenVec3(Vector3 VecA, Vector3 VecB);
	static std::map<uint64_t, bool> keyMapping;

	static class GameMode* currentGM;

	static HMODULE hModule;
};

/* View Matrix BS */
