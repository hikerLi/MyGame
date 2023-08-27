#pragma once

#include "common/type/bg_base_type.h"
#include "mono/jit/jit.h"
#include "mono/metadata/image.h"

#include "mono/metadata/assembly.h"
#include "mono/metadata/appdomain.h"
#include "mono/metadata/object.h"
#include "mono/metadata/metadata.h"
#include "mono/metadata/reflection.h"

namespace BG
{
	class MonoRuntime
	{
	public:
		void initialize(const BGString& appName);

		template<typename... Args>
		BGSharedPtr<MonoObject> invokeMethod(const BGString& namespaceName, const BGString& className, const BGString& methodName, Args... args);

		void end();

	private:
		BGSharedPtr<MonoAssembly> m_assembly_ptr;
		BGSharedPtr<MonoImage> m_image_ptr;
	};

	template<typename ...Args>
	inline BGSharedPtr<MonoObject> MonoRuntime::invokeMethod(const BGString& namespaceName, const BGString& className, const BGString& methodName, Args ...args)
	{
		MonoClass* klass = mono_class_from_name(m_image_ptr.get(), namespaceName, className);
		MonoMethod* method = mono_class_get_method_from_name(klass, methodName, sizeof(args));
		BGVector<Monoobject*> params = {
			mono_value_box(mono_domain_get(), mono_get_double_class(), &args)...
		};

		BGSharedPtr<MonoObject> result_ptr = BGMakeShared<MonoObject>(mono_runtime_invoke(method, nullptr, params.data, nullptr));
		return result_ptr;
	}
}