#pragma once
#include "common/type/bg_base_type.h"
namespace BG
{
	class NetDataPacket
	{
	public:
		NetDataPacket();
		~NetDataPacket();

		UInt64 write(const UByte* buf, UInt64 count);

		UInt64 writeToHead(const UByte* buf, UInt64 count);

		UInt64 getSize();

		UByte* getDataPtr();
	private:
		UByte* m_data;
		/*
			[header:body]
			[len:{traceid}:{clientid}:checkcode:messageid]
		*/
		UInt64 m_head_offset;
		UInt64 m_body_offset;
		const UInt64 m_head_len = 1024;
		const UInt64 m_body_init_len = 4096;
		const UInt64 m_body_incr_len = 1024;
	};
}