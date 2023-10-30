#include "bg_common_global_context.h"

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
		
		m_connection_manager.initialize();
		m_session_manager.initialize();
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
	}
}