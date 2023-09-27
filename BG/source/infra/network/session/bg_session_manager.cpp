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
	NetSession* SessionManager::AllocateNetSession()
	{
		UInt64 session_id = m_session_id_allocator.allocateID();
		NetSession* net_session = new NetSession(session_id);
		m_session_map[session_id] = net_session;
		return net_session;
	}
}