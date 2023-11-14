#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/class.h>
#include <mono/metadata/object.h>
#include <iostream>
#include <stdlib.h>
#define ASSERT_LOG_RETURN(A, NUM, LOG) if (!(A)) \
	{ \
		std::cout << LOG << std::endl;	\
		return NUM; \
	}
int main()
{

	MonoDomain* domain;
	// ��һ�������Ǳ�׼��Ŀ¼���ڶ��������Ѿ�����
	mono_set_dirs("G:\\MyProjects\\Tools\\mono-runtime\\microsoft.netcore.app.runtime.mono.win-x64.7.0.2\\runtimes\\win-x64\\lib\\net7.0", "");
	mono_set_assemblies_path("G:\\MyProjects\\Tools\\mono-runtime\\microsoft.netcore.app.runtime.mono.win-x64.7.0.2\\runtimes\\win-x64\\lib\\net7.0");
	domain = mono_jit_init("TestMono");
	ASSERT_LOG_RETURN(domain != nullptr, 1, "error: domain");
	// �ڶ�����������Ҫ���ص�c#��il
	MonoAssembly* assembly = mono_domain_assembly_open(domain, "G:\\MyProjects\\MyGame\\test\\TestMono\\bin\\Release\\Test.dll");
	ASSERT_LOG_RETURN(assembly != nullptr, 1, "error: assembly");

	MonoImage* image = mono_assembly_get_image(assembly);
	ASSERT_LOG_RETURN(image != nullptr, 1, "error: image");

	MonoClass* main_class = mono_class_from_name(image, "Test", "Class1");
	ASSERT_LOG_RETURN(image != nullptr, 1, "error: main_class");

	MonoMethod* mono_method = mono_class_get_method_from_name(main_class, "Fun", 0);
	ASSERT_LOG_RETURN(mono_method != nullptr, 1, "error: main_class");
	mono_runtime_invoke(mono_method, nullptr, nullptr, nullptr);

	system("pause");
	return 0;
}