#include "bg_command_config.h"

namespace BG
{
	void CommandConfig::parserParam(UInt32 argc, void** argv)
	{
		BGString key, value;
		for (int i = 0; i < argc; i++)
		{
			BGString item = (char*)argv[i];
			if (key.empty() && item.size() > 2 && item[0] == '-' && item[1] == '-')
			{
				key = BGString(item.c_str() + 2);
			}
			else if (!key.empty())
			{
				m_param_config_map[key] = item;
				key.clear();
			}
			else
			{
				//error
			}
		}
	}

	BGString CommandConfig::getParamConfig(const BGString& param_name)
	{
		return m_param_config_map[param_name];
	}
}