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
	Bool TCPConnection::connect(const NetAddr& address, bool need_reconnect)
	{
		asio::ip::tcp::socket socket(m_connection_manager->getIOContext());
		socket.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(address.m_ip), address.m_port));
		m_need_reconnect = need_reconnect;
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
	UInt32 TCPConnection::send(const BGString& message)
	{
		//m_socket->async_send(asio::buffer(message.c_str(), 0xFF));
		return UInt32(0);
	}
	UInt32 TCPConnection::recv(BGString& message)
	{
		//m_socket->async_receive(asio::buffer(message, 0xFF));
		return UInt32(0);
	}
	void TCPConnection::setSocket(const std::shared_ptr<asio::ip::tcp::socket> socket)
	{
		m_socket = socket;
	}
}