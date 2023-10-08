#pragma once
#include "common/type/bg_base_type.h"
namespace BG
{
	class NetDataPacket
	{
	public:
		NetDataPacket();

		UInt64 write(const UByte* buf, UInt64 count);

		UInt64 writeToHead(const UByte* buf, UInt64 count);
	private:
		UByte* m_data;
		/*
			[header:body]
			[len:{traceid}:{clientid}:checkcode:messageid]
		*/
		UInt64 m_head_offset;
		UInt64 m_body_offset;
	};
}