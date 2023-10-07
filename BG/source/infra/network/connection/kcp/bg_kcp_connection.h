#pragma once
#include "network/connection/bg_net_connection_interface.h"

class ConnectionManager;
namespace BG
{
	class KCPConnection : public NetConnectionInterface
	{
	public:
		KCPConnection(UInt64 connection_id, ConnectionManager* connection_manager);
		virtual void initialize();

		virtual Bool connect(const NetAddr& address);

		virtual void shutdown();

		virtual void tick();

		virtual void end();

	private:
		ConnectionManager* m_connection_manager;
	};
}