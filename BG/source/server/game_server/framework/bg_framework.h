#pragma once
#include "script/bg_script_manager.h"

namespace BG
{
	class Framework
	{
	public:
		void initialize(int argc, void* argv[]);

		void begin();

		void run();

		void end();

	private:
		ScriptManager m_script_manager;
		Bool m_running = true;
	};
}