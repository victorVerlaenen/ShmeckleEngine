#pragma once
#include <memory>
#include "Core.h"
#include <format>

namespace Shmeckle
{

	class SM_API Logger
	{
	public:
		static void Initialize();

	private:
		class LoggerPimpl;
		static std::unique_ptr<LoggerPimpl> supLoggerPimpl_;

	public:
		template<class... Args>
		inline static void Trace(std::format_string<Args...> fmtString, Args&&... args) 
		{ 
			Trace(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void Info(std::format_string<Args...> fmtString, Args&&... args)
		{
			Info(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void Warning(std::format_string<Args...> fmtString, Args&&... args)
		{
			Warning(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void Error(std::format_string<Args...> fmtString, Args&&... args)
		{
			Error(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void Critical(std::format_string<Args...> fmtString, Args&&... args)
		{
			Critical(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void TraceCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Trace(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void InfoCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Info(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void WarningCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Warning(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void ErrorCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Error(std::format(fmtString, std::forward<Args>(args)...));
		}

		template<class... Args>
		inline static void CriticalCore(std::format_string<Args...> fmtString, Args&&... args)
		{
			Critical(std::format(fmtString, std::forward<Args>(args)...));
		}

		static void Trace(const std::string& formatedString);
		static void Info(const std::string& formatedString);
		static void Warning(const std::string& formatedString);
		static void Error(const std::string& formatedString);
		static void Critical(const std::string& formatedString);

		static void TraceCore(const std::string& formatedString);
		static void InfoCore(const std::string& formatedString);
		static void WarningCore(const std::string& formatedString);
		static void ErrorCore(const std::string& formatedString);
		static void CriticalCore(const std::string& formatedString);
	};

}
