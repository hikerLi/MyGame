#include <common/json/bg_json_parser.h>
#include <fstream>
#include <common/log/bg_log.h>
namespace BG
{
	JsonParser::JsonParser(const BGString json_file)
	{
		std::ifstream ifs(json_file);
		if (!ifs)
		{
			LOG_ERROR("JsonParser failed to open file:{}.", json_file);
			return;
		}
		ifs >> m_json_obj;
	}
	json JsonParser::getResult()
	{
		return m_json_obj;
	}
}