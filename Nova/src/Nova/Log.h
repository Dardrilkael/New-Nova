#pragma once

//#include "spdlog/spdlog.h"
//#include <spdlog/fmt/ostr.h>
#include "Core.h"


const int WIDTH = 100;
const int HEIGHT = 40;






typedef unsigned short WORD;
typedef void* HANDLE;

namespace Nova
{
	class NOVA_API Log
	{
	public:
		enum level_log
		{
			trace, debug, info, warn, error, critical, fatal, special, off
		};

	
		//static void SetCoreLevel(level_log level);
		static void Init();
		static void Write(std::string text, Log::level_log lvl);
	//	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	//	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		
		
		//static std::shared_ptr<spdlog::logger> s_CoreLogger;
		//static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static HANDLE s_Write_handle;
		static WORD* colors;
	};


#ifdef NOVA_DEBUG
 #define NOVA_CORE_LOG_TRACE(...)     Log::Write(__VA_ARGS__, Log::level_log::trace);
 #define NOVA_CORE_LOG_DEBUG(...)	  Log::Write(__VA_ARGS__, Log::level_log::debug);
 #define NOVA_CORE_LOG_INFO(...)	  Log::Write(__VA_ARGS__, Log::level_log::info);
 #define NOVA_CORE_LOG_WARN(...)	  Log::Write(__VA_ARGS__, Log::level_log::warn);
 #define NOVA_CORE_LOG_ERROR(...)	  Log::Write(__VA_ARGS__, Log::level_log::error);
 #define NOVA_CORE_LOG_CRITICAL(...)  Log::Write(__VA_ARGS__, Log::level_log::critical);
 #define NOVA_CORE_LOG_FATAL(...)	  Log::Write(__VA_ARGS__, Log::level_log::fatal);
 #define NOVA_CORE_LOG_SPECIAL(...)	  Log::Write(__VA_ARGS__, Log::level_log::special);
 #define NOVA_CORE_LOG_OFF(...)		  Log::Write(__VA_ARGS__, Log::level_log::off);

#define NOVA_LOG_TRACE(...)   
#define NOVA_LOG_DEBUG(...)	  
#define NOVA_LOG_INFO(...)	  
#define NOVA_LOG_WARN(...)	  
#define NOVA_LOG_ERROR(...)	  
#define NOVA_LOG_CRITICAL(...)
#define NOVA_LOG_FATAL(...)	  
#define NOVA_LOG_SPECIAL(...)
#define NOVA_LOG_OFF(...)	

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
