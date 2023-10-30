#pragma once

#include "common/pool/bg_object_pool.h"
#include "network/session/bg_net_data_packet.h"
namespace BG
{
	class NetDataPacket;
	class NetDataPacketManager
	{
	public:
		NetDataPacketManager();
		NetDataPacket* allocate();
		void deallocate(NetDataPacket* net_data_packet);

	private:
		ObjectPool<NetDataPacket> m_net_data_packet_pool;
	};
}