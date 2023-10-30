#include "network/connection/bg_connection_manager.h"
#include "network/connection/tcp/bg_tcp_connection.h"
#include "network/connection/kcp/bg_kcp_connection.h"
#include "network/connection/ssl/bg_ssl_connection.h"
#include "common/utils/utils.h"

#include "bg_common_global_context.h"
namespace BG
{
	ConnectionManager::ConnectionManager():m_tcp_socket(m_io_context), m_tcp_acceptor(m_io_context)
	{
		for (auto iter = m_connection_map.begin(); iter != m_connection_map.end(); iter++)
		{
			auto net_connection = iter->second;
			BGFree(net_connection);
		}
	}
	ConnectionManager::~ConnectionManager()
	{
	}
	void ConnectionManager::initialize()
	{
		m_io_thread = std::unique_ptr<std::thread>(new std::thread(&ConnectionManager::runIOThread, this));
	}
	void ConnectionManager::tick()
	{
		for (auto iter = m_connection_map.begin(); iter != m_connection_map.end(); iter++)
		{
			auto connection = iter->second;
			if (connection)
			{
				connection->tick();
			}
		}
	}
	void ConnectionManager::end()
	{
		for (auto iter = m_connection_map.begin(); iter != m_connection_map.end(); iter++)
		{
			auto connection = iter->second;
			if (connection)
			{
				connection->end();
			}
		}
		m_io_context.stop();
		m_tcp_socket.close();
		m_tcp_acceptor.close();
		m_io_thread.release();
	}
	void ConnectionManager::runIOThread()
	{
		m_io_context.run();
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
			net_connection = BGNew<TCPConnection>(connection_id, this);
		}
		else if (protocal == "kcp")
		{
			net_connection = BGNew<KCPConnection>(connection_id, this);
		}
		else if (protocal == "ssl")
		{
			net_connection = BGNew<SSLConnection>(connection_id, this);
		}

		auto net_addr = NetAddr(ip, port, toNetProtocalType(protocal));
		net_connection->connect(net_addr, true);
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
		return NetProtocalType::NetProtocalType_NONE;
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
		TCPConnection* tcp_connection = BGNew<TCPConnection>(connection_id, this);
		tcp_connection->initialize();
		tcp_connection->setSocket(socket);
		m_connection_map[connection_id] = tcp_connection;
		g_common_global_context.m_session_manager.AllocateNetSession()->bindConnection(connection_id);
	}

	void ConnectionManager::kcpListen(UInt16 port)
	{
	}

	void ConnectionManager::kcpAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket)
	{
		UInt64 connection_id = m_connection_id_allocator.allocateID();
		KCPConnection* net_connection = BGNew<KCPConnection>(connection_id, this);
	}

	void ConnectionManager::sslListen(UInt16 port)
	{
	}

	void ConnectionManager::sslAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket)
	{
		UInt64 connection_id = m_connection_id_allocator.allocateID();
		SSLConnection* net_connection = BGNew<SSLConnection>(connection_id, this);
	}

	asio::io_context& ConnectionManager::getIOContext()
	{
		// TODO: 在此处插入 return 语句
		return m_io_context;
	}
}