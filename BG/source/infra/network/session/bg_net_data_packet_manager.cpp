#include "network/session/bg_net_data_packet_manager.h"

namespace BG
{
	NetDataPacketManager::NetDataPacketManager()
	{
	}
	NetDataPacket* NetDataPacketManager::allocate()
	{
		return m_net_data_packet_pool.allocate();
	}
	void NetDataPacketManager::deallocate(NetDataPacket* net_data_packet)
	{
		m_net_data_packet_pool.deallocate(net_data_packet);
	}
}