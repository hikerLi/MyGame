#include "bg_net_connection_interface.h"
#include "thirdparty/asio/include/asio.hpp"
namespace BG
{
	class ConnectionManager
	{
	public:
		void initialize();

		void tick();

		void end();

		void runIOThread();

		void tcpListen(UInt16 port);

		void tcpAcceptCB(asio::ip::tcp::socket* socket);

		asio::io_context& getIOContext();
	private:
		UnorderedMap<UInt64, NetConnectionInterface> m_connection_map;
		asio::io_context m_io_context;
		std::unique_ptr<std::thread> m_io_thread;
		asio::ip::tcp::socket m_tcp_socket;
		asio::ip::tcp::acceptor m_tcp_acceptor;
	};
}