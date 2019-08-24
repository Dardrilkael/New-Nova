#pragma once
//#define USE_DLL

#ifdef NOVA_PLATFORM_WINDOWS
	#ifdef USE_DLL
		#ifdef NOVA_BUILD_DLL
			#define NOVA_API __declspec(dllexport)
		#else 
			#define NOVA_API __declspec(dllimport)
		
		#endif // NOVA_BUILD_DLL

	#endif // USE_DLL
#ifndef USE_DLL
#define NOVA_API
#endif

#endif // NOVA_PLATFORM_WINDOWS

#define BIT(x) (1<<x)

#define NOVA_CORE_ASSERT(x,...) if(!x){ NOVA_CORE_LOG_WARN(__VA_ARGS__);__debugbreak();};

#define NOVA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Nova
{
template <typename T>
using Scope = std::unique_ptr<T>;

template <typename T>
using Ref = std::shared_ptr<T>;

}