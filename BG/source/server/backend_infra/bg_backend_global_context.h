#pragma once

namespace BG
{
	class BackendGlobalContext
	{
	public:
		BackendGlobalContext();
		~BackendGlobalContext();
		void initialize();
		void begin();
		void tick();
		void end();
	private:

	};

	extern BackendGlobalContext g_backend_context;
}