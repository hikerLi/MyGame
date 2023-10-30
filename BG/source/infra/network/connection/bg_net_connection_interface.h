#pragma once
#include "common/type/bg_base_type.h"
#include "fmt/format.h"
namespace BG
{
	class ConnectionManager;

	ENUM NetProtocalType
	{
		NetProtocalType_NONE = 0,
		NetProtocalType_TCP = 1,
		NetProtocalType_KCP = 2,
		NetProtocalType_WS = 3,
		NetProtocalType_HTTP = 4
	};

	class NetAddr
	{
	public:
		NetAddr(const BGString ip, UInt16 port, const NetProtocalType& protocal_type);
		BGString getAddress();


	public:
		BGString m_ip;
		UInt16 m_port;
		NetProtocalType m_protocal_type;
	};

	class NetConnectionInterface
	{
	public:

		NetConnectionInterface(UInt64 connection_id, ConnectionManager* connection_manager);

		virtual void initialize() = 0;

		virtual Bool connect(const NetAddr& address, bool need_reconnect) = 0;

		virtual void shutdown() = 0;

		virtual void tick() = 0;

		virtual void end() = 0;

		virtual UInt32 send(const BGString& message) = 0;

		virtual UInt32 recv(BGString& message) = 0;

	protected:
		UInt64 m_connection_id;
		ConnectionManager* m_connection_manager;
	};
}