#pragma once

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>
#include "Core.h"

namespace Nova
{
	class NOVA_API Log
	{
	public:
		enum class level_log
		{trace,debug,info,warn,error,critical,fatal,special,off};


		static void SetCoreLevel(level_log level);
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static inline spdlog::level::level_enum Convert(level_log level)
		{
			switch (level)
			{
			case level_log::trace:
				return spdlog::level::level_enum::trace;
			case level_log::debug:
				return spdlog::level::level_enum::debug;
			case level_log::info:
				return spdlog::level::level_enum::info;
			case level_log::warn:
				return spdlog::level::level_enum::warn;
			case level_log::error:
				return spdlog::level::level_enum::err;
			case level_log::critical:
				return spdlog::level::level_enum::critical;
			case level_log::fatal:
				return spdlog::level::level_enum::fatal;
			case level_log::special:
				return spdlog::level::level_enum::special;
			case level_log::off:
				return spdlog::level::level_enum::off;
			default:
				return spdlog::level::level_enum::off;
			}
		}
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


#ifdef NOVA_DEBUG
 #define NOVA_CORE_LOG_TRACE(...)      Nova::Log::GetCoreLogger()->trace(__VA_ARGS__)
 #define NOVA_CORE_LOG_DEBUG(...)	   Nova::Log::GetCoreLogger()->debug(__VA_ARGS__)
 #define NOVA_CORE_LOG_INFO(...)	   Nova::Log::GetCoreLogger()->info(__VA_ARGS__)
 #define NOVA_CORE_LOG_WARN(...)	   Nova::Log::GetCoreLogger()->warn(__VA_ARGS__)
 #define NOVA_CORE_LOG_ERROR(...)	   Nova::Log::GetCoreLogger()->error(__VA_ARGS__)
 #define NOVA_CORE_LOG_CRITICAL(...)   Nova::Log::GetCoreLogger()->critical(__VA_ARGS__)
 #define NOVA_CORE_LOG_FATAL(...)	   Nova::Log::GetCoreLogger()->fatal(__VA_ARGS__)
 #define NOVA_CORE_LOG_SPECIAL(...)	   Nova::Log::GetCoreLogger()->special(__VA_ARGS__)
 #define NOVA_CORE_LOG_OFF(...)		   Nova::Log::GetCoreLogger()->off(__VA_ARGS__)

#define NOVA_LOG_TRACE(...)      Nova::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NOVA_LOG_DEBUG(...)	   Nova::Log::GetClientLogger()->debug(__VA_ARGS__)
#define NOVA_LOG_INFO(...)	   Nova::Log::GetClientLogger()->info(__VA_ARGS__)
#define NOVA_LOG_WARN(...)	   Nova::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NOVA_LOG_ERROR(...)	   Nova::Log::GetClientLogger()->error(__VA_ARGS__)
#define NOVA_LOG_CRITICAL(...)   Nova::Log::GetClientLogger()->critical(__VA_ARGS__)
#define NOVA_LOG_FATAL(...)	   Nova::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define NOVA_LOG_SPECIAL(...)	   Nova::Log::GetClientLogger()->special(__VA_ARGS__)
#define NOVA_LOG_OFF(...)		   Nova::Log::GetClientLogger()->off(__VA_ARGS__)

#else
#define NOVA_CORE_LOG_TRACE(...)  
#define NOVA_CORE_LOG_DEBUG(...)	
#define NOVA_CORE_LOG_INFO(...)	
#define NOVA_CORE_LOG_WARN(...)	
#define NOVA_CORE_LOG_ERROR(...)	
#define NOVA_CORE_LOG_CRITICAL(...)
#define NOVA_CORE_LOG_FATAL(...)	
#define NOVA_CORE_LOG_SPECIAL(...)
#define NOVA_CORE_LOG_OFF(...)		

#define NOVA_LOG_TRACE(...)    
#define NOVA_LOG_DEBUG(...)	   
#define NOVA_LOG_INFO(...)	   
#define NOVA_LOG_WARN(...)	   
#define NOVA_LOG_ERROR(...)	   
#define NOVA_LOG_CRITICAL(...) 
#define NOVA_LOG_FATAL(...)	   
#define NOVA_LOG_SPECIAL(...)
#define NOVA_LOG_OFF(...)

#endif

}
