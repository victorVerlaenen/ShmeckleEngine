#pragma once
#include "Core.h"
#include "spdlog\spdlog.h"

namespace shmeckle
{
	enum class LogContext
	{
		Core,
		Client
	};

	enum class LogLevel
	{
		Trace,
		Info,
		Warning,
		Error,
		Critical
	};

	class SHMECKLE_API Logger
	{
	public:
		static void Initialize();
		static void CleanUp();

		// Convenience functions for core logger
		static void CoreTrace(const std::string& text);
		static void CoreInfo(const std::string& text);
		static void CoreWarning(const std::string& text);
		static void CoreError(const std::string& text);
		static void CoreCritical(const std::string& text);

		// Convenience functions for client logger
		static void Trace(const std::string& text);
		static void Info(const std::string& text);
		static void Warning(const std::string& text);
		static void Error(const std::string& text);
		static void Critical(const std::string& text);

	protected:
		Logger() = delete;
		~Logger() = delete;

		Logger(const Logger& other) = delete;
		Logger& operator=(const Logger& other) = delete;
		Logger(Logger&& other) = delete;
		Logger& operator=(Logger&& other) = delete;

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}