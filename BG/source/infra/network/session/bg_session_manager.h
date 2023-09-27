#pragma once
#include "network/session/bg_net_session.h"
#include "common/id_allocator/bg_id_allocator.h"
namespace BG
{
	class SessionManager
	{

	public:
		void tick();

		NetSession* AllocateNetSession();
	private:
		BGUnorderedMap<UInt64, NetSession*> m_session_map;
		IDAllocator<UInt64> m_session_id_allocator;
	};
}