#include "network/connection/tcp/bg_tcp_connection.h"
#include "network/connection/bg_connection_manager.h"
namespace BG
{
	TCPConnection::TCPConnection()
	{
	}

	TCPConnection::~TCPConnection()
	{
	}

	void TCPConnection::initialize(const BG::ConnectionManager* connection_manager)
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