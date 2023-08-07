#include "network/connection/tcp/bg_tcp_connection.h"
#include "network/connection/bg_connection_manager.h"
namespace BG
{
	void TCPConnection::initialize(const ConnectionManager* connection_manager)
	{

	}
	Bool TCPConnection::connect(const NetAddr& address)
	{
		return true;
	}
	void TCPConnection::shutdown()
	{
	}
	void TCPConnection::tick()
	{
	}
	void TCPConnection::end()
	{
	}
}