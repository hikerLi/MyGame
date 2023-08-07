#include "network/connection/bg_net_connection_interface.h"

class ConnectionManager;
namespace BG
{
	class SSLConnection : public NetConnectionInterface
	{
	public:
		virtual void initialize(const ConnectionManager* connection_manager);

		virtual Bool connect(const NetAddr& address);

		virtual void shutdown();

		virtual void tick();

		virtual void end();

	private:
		ConnectionManager* m_connection_manager;
	};
}