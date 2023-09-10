#include "bg_script_manager.h"

namespace BG
{
	void ScriptManager::initialize(BGString script_name)
	{
		m_mono_runtime.initialize(script_name);
	}

	void ScriptManager::end()
	{
		m_mono_runtime.end();
	}
}
