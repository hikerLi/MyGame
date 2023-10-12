#pragma once
#include "network/connection/bg_net_connection_interface.h"
#include "asio.hpp"
#include "common/id_allocator/bg_id_allocator.h"
namespace BG
{
	class ConnectionManager
	{
	public:
		ConnectionManager();
		void initialize();

		void tick();

		void end();

		void runIOThread();

		void connect(const BGString& addr);

		NetProtocalType toNetProtocalType(const BGString& protocal);

		void listen(const BGString& addr);

		void tcpListen(UInt16 port);

		void tcpAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket);

		void kcpListen(UInt16 port);

		void kcpAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket);

		void sslListen(UInt16 port);

		void sslAcceptCB(const asio::error_code& error, const std::shared_ptr<asio::ip::tcp::socket> socket);

		asio::io_context& getIOContext();
	private:
		BGUnorderedMap<UInt64, NetConnectionInterface*> m_connection_map;
		asio::io_context m_io_context;
		std::unique_ptr<std::thread> m_io_thread;
		asio::ip::tcp::socket m_tcp_socket;
		asio::ip::tcp::acceptor m_tcp_acceptor;

		IDAllocator<UInt64> m_connection_id_allocator;
	};
}