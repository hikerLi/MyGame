#include "network/connection/tcp/bg_tcp_connection.h"
#include "network/connection/bg_connection_manager.h"
namespace BG
{
	TCPConnection::TCPConnection(UInt64 connection_id, ConnectionManager* connection_manager) :NetConnectionInterface(connection_id, connection_manager)
	{
	}
	TCPConnection::~TCPConnection()
	{
	}

	void TCPConnection::initialize()
	{

	}
	Bool TCPConnection::connect(const NetAddr& address)
	{
		asio::io_context io_context;
		asio::ip::tcp::socket socket(io_context);
		asio::ip::tcp::resolver resolver(io_context);
		//asio::connect(socket, resolver.resolve(address.m_ip, address.m_port));
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