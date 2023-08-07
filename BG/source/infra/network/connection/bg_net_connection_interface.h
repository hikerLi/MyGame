#include "common/type/bg_base_type.h"

namespace BG
{

	ENUM NetProtocalType
	{
		NetProtocalType_TCP = 0,
		NetProtocalType_KCP,
		NetProtocalType_WS,
		NetProtocalType_HTTP
	};

	class NetAddr
	{
	public:
		NetAddr(const String ip, UInt16 port, NetProtocalType protocal_type);
		String getAddress();
	private:
		String m_ip;
		UInt16 m_port;
		NetProtocalType m_protocal_type;
	};

	class ConnectionManager;
	class NetConnectionInterface
	{
	public:
		
		virtual void initialize(const ConnectionManager* connection_manager) = 0;

		virtual Bool connect(const NetAddr& address) = 0;

		virtual void shutdown() = 0;

		virtual void tick() = 0;

		virtual void end() = 0;

	protected:
		UInt64 m_connection_id;
	};
}