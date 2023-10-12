#include "bg_common_global_context.h"

namespace BG
{
	CommonGlobalContext g_common_global_context;
	CommonGlobalContext::CommonGlobalContext() 
	{
	}

	CommonGlobalContext::~CommonGlobalContext()
	{
	}

	void CommonGlobalContext::initialize()
	{
		BGString inner_addr = m_command_config.getParamConfig("inner_addr");

	}

	void CommonGlobalContext::end()
	{
	}
}