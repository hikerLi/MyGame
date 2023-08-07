#include "network/connection/bg_connection_manager.h"
#include "network/connection/tcp/bg_tcp_connection.h"
namespace BG
{
	void ConnectionManager::initialize()
	{
		m_io_thread = std::unique_ptr<std::thread>(new std::thread(&ConnectionManager::runIOThread, this));
	}
	void ConnectionManager::tick()
	{
	}
	void ConnectionManager::end()
	{
	}
	void ConnectionManager::runIOThread()
	{
		m_io_context.run();
	}
	void ConnectionManager::tcpListen(UInt16 port)
	{
		m_tcp_acceptor = asio::ip::tcp::acceptor(m_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
		m_tcp_socket = asio::ip::tcp::socket(m_io_context);
		m_tcp_acceptor.async_accept(m_tcp_socket, std::bind(tcpAcceptCB, this));
	}
	void ConnectionManager::tcpAcceptCB(asio::ip::tcp::socket* socket)
	{
		//create tcp_listner,确定创建tcpconnection和session
		TCPConnection* tcp_connection = new TCPConnection();
		tcp_connection->initialize(this, socket);
		//m_connection_map[] = tcp_connection;
	}
	asio::io_context& ConnectionManager::getIOContext()
	{
		// TODO: 在此处插入 return 语句
		return m_io_context;
	}
}