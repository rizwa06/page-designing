#pragma once
#include <string>
#include <locale>
#include <codecvt>

namespace Utilities
{
	std::string convert_plat_string(Platform::String^ text_field);
	Platform::String^ stringToPlatformString(std::string inputString);
};