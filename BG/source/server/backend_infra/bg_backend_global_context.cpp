#include "bg_backend_global_context.h"

namespace BG
{
	BackendGlobalContext::BackendGlobalContext()
	{
		m_mono_runtime_ptr = new MonoRuntime();
	}

	BackendGlobalContext::~BackendGlobalContext()
	{
		delete m_mono_runtime_ptr;
	}

	void BackendGlobalContext::initialize()
	{
		m_mono_runtime_ptr->initialize("");
	}

	void BackendGlobalContext::end()
	{
		m_mono_runtime_ptr->end();
	}
}
