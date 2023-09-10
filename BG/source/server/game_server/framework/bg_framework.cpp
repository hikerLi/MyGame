#include "bg_framework.h"
#include "bg_common_global_context.h"
namespace BG
{
	void Framework::initialize(int argc, void* argv[])
	{
		g_common_global_context.m_command_config.parserParam(argc, argv);

		BGString script_name = g_common_global_context.m_command_config.getParamConfig("service_name");
		m_script_manager.initialize(script_name);
	}

	void Framework::begin()
	{
	}

	void Framework::run()
	{
	}

	void Framework::end()
	{
		m_script_manager.end();
	}
}
