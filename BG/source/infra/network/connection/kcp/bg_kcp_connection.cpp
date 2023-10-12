#include "network/connection/kcp/bg_kcp_connection.h"

namespace BG
{
	KCPConnection::KCPConnection(UInt64 connection_id, ConnectionManager* connection_manager) :NetConnectionInterface(connection_id, connection_manager)
	{
	}
	void KCPConnection::initialize()
	{
	}
	Bool KCPConnection::connect(const NetAddr& address, bool need_reconnect)
	{
		return false;
	}
	void KCPConnection::shutdown()
	{
	}
	void KCPConnection::tick()
	{
	}
	void KCPConnection::end()
	{
	}
	UInt32 KCPConnection::send(const BGString& message)
	{
		return UInt32(0);
	}
	UInt32 KCPConnection::recv(BGString& message)
	{
		return UInt32(0);
	}
}