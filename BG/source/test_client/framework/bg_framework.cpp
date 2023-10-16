#include "bg_framework.h"
#include "bg_common_global_context.h"
namespace BG
{
	void Framework::initialize(int argc, void* argv[])
	{
		g_common_global_context.m_command_config.parserParam(argc, argv);

		BGString script_name = g_common_global_context.m_command_config.getParamConfig("service_name");
		script_name = "client";
		m_script_manager.initialize(script_name);
		g_common_global_context.initialize();
	}

	void Framework::begin()
	{
		m_script_manager.begin();
	}

	void Framework::run()
	{
		while (m_running)
		{
			m_script_manager.run();
		}
	}

	void Framework::end()
	{
		m_script_manager.end();
	}
}
