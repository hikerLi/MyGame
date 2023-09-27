#pragma once
#include "network/connection/bg_net_connection_interface.h"

namespace BG
{
	class ConnectionManager;
	class TCPConnection : public NetConnectionInterface
	{
	public:

		TCPConnection(UInt64 connection_id, ConnectionManager* connection_manager);
		virtual ~TCPConnection();

		virtual void initialize();

		virtual Bool connect(const NetAddr& address, bool need_reconnect);

		virtual void shutdown();

		virtual void tick();

		virtual void end();

		virtual UInt32 send(const BGString& message);

		virtual UInt32 recv(BGString& message);

		void setSocket(const std::shared_ptr<asio::ip::tcp::socket> socket);
	private:
		std::shared_ptr<asio::ip::tcp::socket> m_socket;
		bool m_need_reconnect;
	};
}