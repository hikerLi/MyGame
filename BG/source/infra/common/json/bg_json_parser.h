#pragma once
#include <common/type/bg_base_type.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
namespace BG
{
	class JsonParser
	{
	public:
		JsonParser(const BGString json_file);

		json getResult();
	private:
		json m_json_obj;
	};
}