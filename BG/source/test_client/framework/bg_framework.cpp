#include "bg_framework.h"
#include "bg_common_global_context.h"
namespace BG
{
	void Framework::initialize(int argc, void* argv[])
	{
		g_common_global_context.m_command_config.parserParam(argc, argv);

		BGString script_name = g_common_global_context.m_command_config.getParamConfig("service_name");
		script_name = "client";
		g_common_global_context.initialize();
	}

	void Framework::begin()
	{
		g_common_global_context.begin();
	}

	void Framework::run()
	{
		while (m_running)
		{
			g_common_global_context.tick();
		}
	}

	void Framework::end()
	{
		g_common_global_context.end();
	}
}
