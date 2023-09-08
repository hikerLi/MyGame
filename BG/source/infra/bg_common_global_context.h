#pragma once

#include "common/command_config/bg_command_config.h"
namespace BG
{
	class CommonGlobalContext
	{
	public:
		CommonGlobalContext();
		~CommonGlobalContext();
		void initialize();

		void end();

	public:
		CommandConfig m_command_config;
	};

	extern CommonGlobalContext g_common_global_context;
}