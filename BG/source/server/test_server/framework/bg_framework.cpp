#include "bg_framework.h"
#include "bg_common_global_context.h"
namespace BG
{
	void Framework::initialize(int argc, void* argv[])
	{
		g_common_global_context.m_command_config.parserParam(argc, argv);
		g_common_global_context.initialize();
		BGString script_name = g_common_global_context.m_command_config.getParamConfig("service_name");
		script_name = "test_server";
		
		
	}

	void Framework::begin()
	{
		g_common_global_context.begin();

		BGString inner_addr = g_common_global_context.m_command_config.getParamConfig("inner_addr");
		g_common_global_context.m_connection_manager.listen(inner_addr);
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
