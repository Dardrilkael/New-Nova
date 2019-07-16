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
