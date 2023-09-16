#include "bg_script_manager.h"
#include "common/utils/utils.h"
#include <iostream>
namespace BG
{
	void ScriptManager::initialize(BGString script_name)
	{
		m_script_name = Utils::toCamelCase(script_name);
		
		m_mono_runtime.initialize(m_script_name);
		std::cout << "scriptmanager script_name:" << m_script_name << std::endl;
	}

	void ScriptManager::begin()
	{
		m_mono_runtime.invokeMethod(m_script_name + ".Application", "BG_" + m_script_name, "begion");
	}

	void ScriptManager::run()
	{
		m_mono_runtime.invokeMethod(m_script_name + ".Application", "BG_" + m_script_name, "run");
	}

	void ScriptManager::end()
	{
		m_mono_runtime.invokeMethod(m_script_name + ".Application", "BG_" + m_script_name, "end");
		m_mono_runtime.end();
	}
}
