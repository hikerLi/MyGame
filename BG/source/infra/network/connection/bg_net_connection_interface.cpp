#include "bg_net_connection_interface.h"

namespace BG
{
	NetAddr::NetAddr(const BGString ip, UInt16 port, const NetProtocalType& protocal_type)
		:m_ip(ip), m_port(port), m_protocal_type(protocal_type)
	{
	}
	BGString NetAddr::getAddress()
	{
		return fmt::format("{}:{}:{}", m_ip.c_str(), m_port, int(m_protocal_type));
		//return m_ip;
	}

	NetConnectionInterface::NetConnectionInterface(UInt64 connection_id, ConnectionManager* connection_manager) :
		m_connection_id(connection_id), m_connection_manager(connection_manager)
	{

	}
}