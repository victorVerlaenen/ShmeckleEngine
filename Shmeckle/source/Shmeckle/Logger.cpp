#include "smpch.h"
#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace shmeckle
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger = nullptr;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger = nullptr;

	void Logger::Initialize()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("SHMECKLE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	void Logger::CleanUp()
	{

	}

	void Logger::CoreTrace(const std::string& text) { s_CoreLogger->trace(text); }
	void Logger::CoreInfo(const std::string& text) { s_CoreLogger->info(text); }
	void Logger::CoreWarning(const std::string& text) { s_CoreLogger->warn(text); }
	void Logger::CoreError(const std::string& text) { s_CoreLogger->error(text); }
	void Logger::CoreCritical(const std::string& text) { s_CoreLogger->critical(text); }

	void Logger::Trace(const std::string& text) { s_ClientLogger->trace(text); }
	void Logger::Info(const std::string& text) { s_ClientLogger->info(text); }
	void Logger::Warning(const std::string& text) { s_ClientLogger->warn(text); }
	void Logger::Error(const std::string& text) { s_ClientLogger->error(text); }
	void Logger::Critical(const std::string& text) { s_ClientLogger->critical(text); }
}
