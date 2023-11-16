#include "bg_common_global_context.h"
#include "common/log/bg_log.h"
namespace BG
{
	CommonGlobalContext g_common_global_context;
	CommonGlobalContext::CommonGlobalContext() 
	{
	}

	CommonGlobalContext::~CommonGlobalContext()
	{
	}

	void CommonGlobalContext::initialize()
	{
		BGString script_name = g_common_global_context.m_command_config.getParamConfig("service_name");
		g_log_context.initialize(LOG_TYPE_TRACE, script_name);
		m_connection_manager.initialize();
		m_session_manager.initialize();
		m_script_manager.initialize(script_name);
	}

	void CommonGlobalContext::begin()
	{
		m_script_manager.begin();
	}

	void CommonGlobalContext::tick()
	{
		m_connection_manager.tick();
		m_session_manager.tick();
	}

	void CommonGlobalContext::end()
	{
		m_connection_manager.end();
		m_session_manager.end();
		m_script_manager.end();
	}
}