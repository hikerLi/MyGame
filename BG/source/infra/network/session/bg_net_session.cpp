#include "network/session/bg_net_session.h"
namespace BG
{
	NetSession::NetSession(UInt64 session_id) : m_session_id(session_id)
	{
	}

	void NetSession::initialize()
	{
	}

	void NetSession::tick()
	{
	}

	void NetSession::end()
	{
	}

	void NetSession::sendData(const NetDataPacket& net_data_packet)
	{
	}

	bool NetSession::bindConnection(UInt64 bind_connection_id)
	{
		if (m_connection_ids.size() >= PER_SESSION_MAX_CONNECTION_NUM)
		{
			return false;
		}
		m_connection_ids[m_connection_ids.size()] = bind_connection_id;
		return true;
	}
}