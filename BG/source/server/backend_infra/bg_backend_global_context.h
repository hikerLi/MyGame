#pragma once

#include <mono_runtime/bg_mono_runtime.h>

namespace BG
{
	class BackendGlobalContext
	{
	public:
		BackendGlobalContext();
		~BackendGlobalContext();
		void initialize();

		void end();
	private:
		MonoRuntime* m_mono_runtime_ptr;
	};

	extern BackendGlobalContext g_backend_context;
}