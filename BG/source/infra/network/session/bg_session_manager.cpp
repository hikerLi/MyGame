#include "bg_session_manager.h"

namespace BG
{
	void SessionManager::tick()
	{
		for (auto iter = m_session_map.begin(); iter != m_session_map.end(); iter++)
		{
			auto session = iter->second;
			if (session != nullptr)
			{
				session->tick();
			}
		}
	}
}