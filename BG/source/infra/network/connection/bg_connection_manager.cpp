#include "network/connection/bg_connection_manager.h"
#include "network/connection/tcp/bg_tcp_connection.h"
#include "network/connection/kcp/bg_kcp_connection.h"
#include "network/connection/ssl/bg_ssl_connection.h"
#include "common/utils/utils.h"
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
		//m_io_context.run();
	}
	void ConnectionManager::connect(const BGString& addr)
	{
		BGVector<BGString> addr_vec = Utils::splitString(addr, ':');
		if (addr_vec.size() < 3)
		{
			return;
		}

		BGString ip = addr_vec[0];
		UInt16 port = atoi(addr_vec[1].c_str());
		BGString protocal = addr_vec[2];
		NetConnectionInterface* net_connection;
		UInt64 connection_id = m_connection_id_allocator.allocateID();
		if (protocal == "tcp")
		{
			net_connection = new TCPConnection(connection_id, this);
		}
		else if (protocal == "kcp")
		{
			net_connection = new KCPConnection(connection_id, this);
		}
		else if (protocal == "ssl")
		{
			net_connection = new SSLConnection(connection_id, this);
		}

		auto net_addr = NetAddr(ip, port, toNetProtocalType(protocal));
		net_connection->connect(net_addr);
	}

	NetProtocalType ConnectionManager::toNetProtocalType(const BGString& protocal)
	{
		if (protocal == "tcp")
		{
			return NetProtocalType::NetProtocalType_TCP;
		}
		else if (protocal == "kcp")
		{
			return NetProtocalType::NetProtocalType_KCP;
		}
		else if (protocal == "http")
		{
			return NetProtocalType::NetProtocalType_HTTP;
		}
		else if (protocal == "ws")
		{
			return NetProtocalType::NetProtocalType_WS;
		}
	}

	void ConnectionManager::listen(const BGString& addr)
	{
		BGVector<BGString> addr_vec =  Utils::splitString(addr, ':');
		if (addr_vec.size() < 3)
		{
			return;
		}

		BGString ip = addr_vec[0];
		UInt16 port = atoi(addr_vec[1].c_str());
		BGString protocal = addr_vec[2];
		if (protocal == "tcp")
		{
			tcpListen(port);
		}
		else if (protocal == "kcp")
		{
			kcpListen(port);

		}
		else if (protocal == "ssl")
		{
			
		}
	}
	void ConnectionManager::tcpListen(UInt16 port)
	{
		m_tcp_acceptor = asio::ip::tcp::acceptor(m_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
		m_tcp_socket = asio::ip::tcp::socket(m_io_context);
		m_tcp_acceptor.async_accept(m_tcp_socket, [this, tcp_socket = std::make_shared<asio::ip::tcp::socket>(m_io_context)](const asio::error_code& error)
			{
				tcpAcceptCB(error, tcp_socket);
			});
	}
	void ConnectionManager::tcpAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket)
	{
		//create tcp_listner,确定创建tcpconnection和session
		UInt64 connection_id = m_connection_id_allocator.allocateID();
		TCPConnection* tcp_connection = new TCPConnection(connection_id, this);
		tcp_connection->initialize();
		//m_connection_map[] = tcp_connection;
	}

	void ConnectionManager::kcpListen(UInt16 port)
	{
	}

	void ConnectionManager::kcpAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket)
	{
		UInt64 connection_id = m_connection_id_allocator.allocateID();
		KCPConnection* net_connection = new KCPConnection(connection_id, this);
	}

	void ConnectionManager::sslListen(UInt16 port)
	{
	}

	void ConnectionManager::sslAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket)
	{
		UInt64 connection_id = m_connection_id_allocator.allocateID();
		SSLConnection* net_connection = new SSLConnection(connection_id, this);
	}

	asio::io_context& ConnectionManager::getIOContext()
	{
		// TODO: 在此处插入 return 语句
		return m_io_context;
	}
}