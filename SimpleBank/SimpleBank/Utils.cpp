#include "pch.h"
#include "Utils.h"

namespace Utilities
{
	std::string convert_plat_string(Platform::String^ text_field)
	{
		std::wstring wtext(text_field->Begin());
		std::string text(wtext.begin(), wtext.end());

		return text;
	}
	Platform::String ^ stringToPlatformString(std::string inputString)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		std::wstring intermediateForm = converter.from_bytes(inputString);
		Platform::String^ retVal = ref new Platform::String(intermediateForm.c_str());

		return retVal;
	}
};