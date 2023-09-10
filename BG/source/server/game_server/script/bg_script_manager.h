#pragma once
#include "common/type/bg_base_type.h"
#include "mono_runtime/bg_mono_runtime.h"
namespace BG
{
	class ScriptManager
	{
	public:
		void initialize(BGString script_name);

		void end();
	private:
		MonoRuntime m_mono_runtime;
	};
}