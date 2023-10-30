#include "network/session/bg_net_data_packet.h"

namespace BG
{
	NetDataPacket::NetDataPacket() : m_head_offset(0), m_body_offset(0)
	{
	}

	NetDataPacket::~NetDataPacket()
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
	UInt64 NetDataPacket::getSize()
	{
		return m_head_offset + m_body_offset;
	}
	UByte* NetDataPacket::getDataPtr()
	{
		return nullptr;
	}
}