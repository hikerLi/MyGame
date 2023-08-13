#pragma once
#include "network/session/bg_net_session.h"

namespace BG
{
	class SessionManager
	{

	public:
		void tick();
	private:
		BGUnorderedMap<UInt64, NetSession*> m_session_map;
	};
}