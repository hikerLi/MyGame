#pragma once

namespace BG
{
	class NetDataPacket;
	class NetDataPacketManager
	{
	public:
		NetDataPacket* allocateNetDataPacket();
	};
}