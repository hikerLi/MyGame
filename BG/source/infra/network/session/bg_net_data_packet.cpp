#include "network/session/bg_net_data_packet.h"

namespace BG
{
	NetDataPacket::NetDataPacket()
	{
	}

	UInt64 NetDataPacket::write(const UByte* buf, UInt64 count)
	{
		return 0;
	}

	UInt64 NetDataPacket::writeToHead(const UByte* buf, UInt64 count)
	{
		return UInt64();
	}
}