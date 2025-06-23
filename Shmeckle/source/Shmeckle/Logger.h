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
		inline static void TraceCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Trace(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		inline static void InfoCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Info(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		inline static void WarningCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Warning(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		inline static void ErrorCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Error(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<typename... Args>
		inline static void CriticalCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Critical(std::format(fmtString, std::forward<Args>(args)...));
		}

		SHM_API static void Trace(const std::string& formatedString);
		SHM_API static void Info(const std::string& formatedString);
		SHM_API static void Warning(const std::string& formatedString);
		SHM_API static void Error(const std::string& formatedString);
		SHM_API static void Critical(const std::string& formatedString);

		static void TraceCore(const std::string& formatedString);
		static void InfoCore(const std::string& formatedString);
		static void WarningCore(const std::string& formatedString);
		static void ErrorCore(const std::string& formatedString);
		static void CriticalCore(const std::string& formatedString);
	};

}