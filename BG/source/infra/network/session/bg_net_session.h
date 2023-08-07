#include "common/type/bg_base_type.h"

namespace BG
{

	ENUM NetSessionStatus
	{
		NetSessionStatus_INITIAL = 0,
		NetSessionStatus_CONNECTED,
		NetSessionStatus_DISCONNECTED,
		NetSessionStatus_RECONNECTING
	};

#define PER_SESSION_MAX_CONNECTION_NUM 5
	class NetSession
	{

	public:
		void initialize();
		void tick();
		void end();

	private:
		UInt64 m_session_id;
		NetSessionStatus m_net_status;

		Array<UInt64, PER_SESSION_MAX_CONNECTION_NUM> m_connection_ids;
	};
}