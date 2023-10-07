#pragma once
#include "common/type/bg_base_type.h"
namespace BG
{
	class Utils
	{
	public:
		static BGString toCamelCase(const BGString& str);
		static BGVector<BGString> splitString(const BGString& s, char delim);
	};
}