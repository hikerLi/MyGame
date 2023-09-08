#pragma once

#include "common/type/bg_base_type.h"
namespace BG
{
	class CommandConfig
	{
	public:
		void parserParam(UInt32 argc, void** argv);

		BGString getParamConfig(const BGString& param_name);
	private:
		BGUnorderedMap<BGString, BGString> m_param_config_map;
	};
}