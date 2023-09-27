#pragma once
#include "common/type/bg_base_type.h"
#include "network/session/bg_net_data_packet.h"
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
		NetSession(UInt64 session_id);
		void initialize();
		void tick();
		void end();

		void sendData(const NetDataPacket& net_data_packet);

		NetDataPacket recvData();

		bool bindConnection(UInt64 bind_connection_id);
	private:
		UInt64 m_session_id;
		NetSessionStatus m_net_status;

		BGArray<UInt64, PER_SESSION_MAX_CONNECTION_NUM> m_connection_ids;
	};
}