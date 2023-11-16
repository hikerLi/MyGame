#pragma once

#include "common/command_config/bg_command_config.h"
#include "network/connection/bg_connection_manager.h"
#include "network/session/bg_session_manager.h"
#include "script/bg_script_manager.h"
namespace BG
{
	class CommonGlobalContext
	{
	public:
		CommonGlobalContext();
		~CommonGlobalContext();
		void initialize();
		void begin();
		void tick();
		void end();

	public:
		CommandConfig m_command_config;
		ConnectionManager m_connection_manager;
		SessionManager m_session_manager;
		ScriptManager m_script_manager;
	};

	extern CommonGlobalContext g_common_global_context;
}