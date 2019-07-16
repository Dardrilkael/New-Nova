#include "novapch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Nova
{
	 std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	 std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	 void Log::SetCoreLevel(level_log level) { s_CoreLogger->set_level(Convert(level)); }

	 void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger = spdlog::stdout_color_mt("Nova Engine");

		s_ClientLogger->set_level(spdlog::level::trace);
		s_CoreLogger->set_level(spdlog::level::trace);

		s_CoreLogger->debug("Initializing Log");
	}

}