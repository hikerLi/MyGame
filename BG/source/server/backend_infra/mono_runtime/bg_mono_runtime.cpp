#include "mono_runtime\bg_mono_runtime.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/class.h>
#include <mono/metadata/object.h>
#include <common/log/bg_log.h>
#include <iostream>
namespace BG
{
	void MonoRuntime::initialize(const BGString& appName)
	{
		LOG_INFO("MonoRuntime script_name:{}", appName);
		mono_set_dirs("G:\\MyProjects\\Tools\\microsoft.netcore.app.runtime.mono.win-x64.7.0.10", "");
		BGString assemble_path = "G:\\MyProjects\\MyGame\\BG\\apps\\GameServer\\bin\\Debug\\net7.0";
		mono_set_assemblies_path(assemble_path.c_str());
		//auto domain = mono_jit_init_version(appName.c_str(), nullptr);
		auto domain = mono_jit_init((appName + ".dll").c_str());
		m_assembly_ptr = mono_domain_assembly_open(domain, (assemble_path + "\\" + (appName + ".dll")).c_str());

		m_image_ptr = mono_assembly_get_image(m_assembly_ptr);
	}

	void MonoRuntime::end()
	{
		mono_jit_cleanup(mono_domain_get());
	}
}