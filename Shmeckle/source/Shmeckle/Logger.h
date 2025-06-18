#pragma once
#include <memory>
#include <format>

#include "Core.h"

namespace Shmeckle
{

	class Logger
	{
	public:
		SHM_API static void Initialize();

	private:
		class LoggerPimpl;
		static std::unique_ptr<LoggerPimpl> supLoggerPimpl_;

	public:
		template<typename... Args>
		SHM_API inline static void Trace(std::format_string<Args...> fmtString, Args&&... args)
		{
			Trace(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void Info(std::format_string<Args...> fmtString, Args&&... args)
		{
			Info(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void Warning(std::format_string<Args...> fmtString, Args&&... args)
		{
			Warning(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void Error(std::format_string<Args...> fmtString, Args&&... args)
		{
			Error(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void Critical(std::format_string<Args...> fmtString, Args&&... args)
		{
			Critical(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void TraceCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Trace(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void InfoCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Info(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void WarningCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Warning(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void ErrorCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Error(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		SHM_API inline static void CriticalCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Critical(std::format(fmtString, std::forward<Args>(args)...));
		}

		SHM_API static void Trace(const std::string& formatedString);
		SHM_API static void Info(const std::string& formatedString);
		SHM_API static void Warning(const std::string& formatedString);
		SHM_API static void Error(const std::string& formatedString);
		SHM_API static void Critical(const std::string& formatedString);

		SHM_API static void TraceCore(const std::string& formatedString);
		SHM_API static void InfoCore(const std::string& formatedString);
		SHM_API static void WarningCore(const std::string& formatedString);
		SHM_API static void ErrorCore(const std::string& formatedString);
		SHM_API static void CriticalCore(const std::string& formatedString);
	};

}

// Logging macros
#define SM_TRACE(...) ::Shmeckle::Logger::Trace(__VA_ARGS__)
#define SM_INFO(...) ::Shmeckle::Logger::Info(__VA_ARGS__)
#define SM_WARNING(...) ::Shmeckle::Logger::Warning(__VA_ARGS__)
#define SM_ERROR(...) ::Shmeckle::Logger::Error(__VA_ARGS__)
#define SM_CRITICAL(...) ::Shmeckle::Logger::Critical(__VA_ARGS__)

#define SM_TRACE_CORE(...) ::Shmeckle::Logger::TraceCore(__VA_ARGS__)
#define SM_INFO_CORE(...) ::Shmeckle::Logger::InfoCore(__VA_ARGS__)
#define SM_WARNING_CORE(...) ::Shmeckle::Logger::WarningCore(__VA_ARGS__)
#define SM_ERROR_CORE(...) ::Shmeckle::Logger::ErrorCore(__VA_ARGS__)
#define SM_CRITICAL_CORE(...) ::Shmeckle::Logger::CriticalCore(__VA_ARGS__)