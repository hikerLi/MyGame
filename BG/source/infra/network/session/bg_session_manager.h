#include "network/session/bg_net_session.h"

namespace BG
{
	class SessionManager
	{

	public:
		void tick();
	private:
		UnorderedMap<UInt64, NetSession*> m_session_map;
	};
}