#include "bg_net_connection_interface.h"
#include "thirdparty/fmt/include/fmt/format.h"
namespace BG
{
	NetAddr::NetAddr(const String ip, UInt16 port, NetProtocalType protocal_type)
		:m_ip(ip), m_port(port), m_protocal_type(protocal_type)
	{
	}
	String NetAddr::getAddress()
	{
		return fmt::format("{}:{}:{}", m_ip, m_port, m_protocal_type);
		//return m_ip;
	}
}