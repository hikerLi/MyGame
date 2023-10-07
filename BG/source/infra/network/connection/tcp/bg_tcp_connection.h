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

		virtual Bool connect(const NetAddr& address);

		virtual void shutdown();

		virtual void tick();

		virtual void end();

	private:
		
	};
}