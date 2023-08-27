#include "mono_runtime\bg_mono_runtime.h"

namespace BG
{
	void MonoRuntime::initialize(const BGString& appName)
	{
		mono_jit_init(appName.c_str());
		m_assembly_ptr = BGMakeShared<MonoAssembly>(mono_domain_assembly_open(mono_domain_get(), (appName + ".dll").c_str()));

		m_image_ptr = BGMakeShared<MonoImage>(mono_assembly_get_image(m_assembly_ptr.get()));
	}

	void MonoRuntime::end()
	{
		mono_jit_cleanup(mono_domain_get());
	}
}