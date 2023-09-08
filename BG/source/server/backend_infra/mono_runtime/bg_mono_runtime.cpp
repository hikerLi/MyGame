#include "mono_runtime\bg_mono_runtime.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/class.h>
#include <mono/metadata/object.h>
namespace BG
{
	void MonoRuntime::initialize(const BGString& appName)
	{
		auto domain = mono_jit_init(appName.c_str());

		m_assembly_ptr = mono_domain_assembly_open(domain, (appName + ".dll").c_str());

		m_image_ptr = mono_assembly_get_image(m_assembly_ptr);
	}

	void MonoRuntime::end()
	{
		mono_jit_cleanup(mono_domain_get());
	}
}