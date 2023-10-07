#include "network/connection/ssl/bg_ssl_connection.h"

namespace BG
{
	SSLConnection::SSLConnection(UInt64 connection_id, ConnectionManager* connection_manager) :NetConnectionInterface(connection_id, connection_manager)
	{
	}
	void SSLConnection::initialize()
	{
	}
	Bool SSLConnection::connect(const NetAddr& address)
	{
		return Bool();
	}
	void SSLConnection::shutdown()
	{
	}
	void SSLConnection::tick()
	{
	}
	void SSLConnection::end()
	{
	}
}