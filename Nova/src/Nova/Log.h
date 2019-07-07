#pragma once

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>
#include "Core.h"

namespace Nova
{
	class NOVA_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


#ifdef NOVA_DEBUG
 #define NOVA_CORE_LOG_TRACE(...)      Log::GetCoreLogger()->trace(__VA_ARGS__)
 #define NOVA_CORE_LOG_DEBUG(...)	   Log::GetCoreLogger()->debug(__VA_ARGS__)
 #define NOVA_CORE_LOG_INFO(...)	   Log::GetCoreLogger()->info(__VA_ARGS__)
 #define NOVA_CORE_LOG_WARN(...)	   Log::GetCoreLogger()->warn(__VA_ARGS__)
 #define NOVA_CORE_LOG_ERROR(...)	   Log::GetCoreLogger()->error(__VA_ARGS__)
 #define NOVA_CORE_LOG_CRITICAL(...)   Log::GetCoreLogger()->critical(__VA_ARGS__)
 #define NOVA_CORE_LOG_FATAL(...)	   Log::GetCoreLogger()->fatal(__VA_ARGS__)
 #define NOVA_CORE_LOG_SPECIAL(...)	   Log::GetCoreLogger()->special(__VA_ARGS__)
 #define NOVA_CORE_LOG_OFF(...)		   Log::GetCoreLogger()->off(__VA_ARGS__)

#endif

}
