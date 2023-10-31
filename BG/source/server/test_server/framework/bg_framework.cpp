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
		m_script_manager.initialize(script_name);
		
	}

	void Framework::begin()
	{
		m_script_manager.begin();

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
		m_script_manager.end();
	}
}
