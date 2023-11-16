#pragma once

#include "common/type/bg_base_type.h"
#include "mono/jit/jit.h"
#include <mono/metadata/assembly.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/class.h>
#include <mono/metadata/object.h>

namespace BG
{
	class MonoRuntime
	{
	public:
		void initialize(const BGString& appName);

		template<typename... Args>
		MonoObject* invokeMethod(const BGString& namespaceName, const BGString& className, const BGString& methodName, Args... args);

		void end();

	private:
		MonoAssembly* m_assembly_ptr{ nullptr};
		MonoImage* m_image_ptr{ nullptr };
	};

	template<typename ...Args>
	inline MonoObject* MonoRuntime::invokeMethod(const BGString& namespaceName, const BGString& className, const BGString& methodName, Args ...args)
	{
		MonoClass* klass = mono_class_from_name(m_image_ptr, namespaceName.c_str(), className.c_str());
		UInt32 param_count = sizeof...(args);
		MonoMethod* method = mono_class_get_method_from_name(klass, methodName.c_str(), param_count);
		/*BGVector<MonoObject*> params = {
			mono_value_box(mono_domain_get(), mono_get_double_class(), &args)...
		};*/
		void* params = nullptr;
		if (param_count > 0)
		{
			params = { &args... };
		}

		MonoObject* exc = nullptr;
		MonoObject* result = mono_runtime_invoke(method, nullptr, &params, &exc);
		if (exc) {
			MonoString* message = mono_object_to_string(exc, nullptr);
			//std::cerr << "Exception thrown: " << mono_string_to_utf8(message) << std::endl;
			return nullptr;
		}
		return result;
		//BGSharedPtr<MonoObject> result_ptr;// = BGMakeShared<MonoObject>(mono_runtime_invoke(method, nullptr, &params, &exc));
		//return result_ptr;
	}
}