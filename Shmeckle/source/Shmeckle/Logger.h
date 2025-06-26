#pragma once
#include <memory>
#include <string>
#include <format>

#include "Core.h"

namespace Shmeckle
{

	class Logger
	{
	public:
		SHM_API static void Initialize();

	private:
		class Impl;
		static std::unique_ptr<Impl> impl_;
	
	public:
		SHM_API static void Trace(const std::string& text);
		template<typename... Args>
		static void Trace(std::string_view fmtStr, Args&&... args)
		{
			Trace(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void Info(const std::string& text);
		template<typename... Args>
		static void Info(std::string_view fmtStr, Args&&... args)
		{
			Info(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}
		
		SHM_API static void Warning(const std::string& text);
		template<typename... Args>
		static void Warning(std::string_view fmtStr, Args&&... args)
		{
			Warning(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void Error(const std::string& text);
		template<typename... Args>
		static void Error(std::string_view fmtStr, Args&&... args)
		{
			Error(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void Critical(const std::string& text);
		template<typename... Args>
		static void Critical(std::string_view fmtStr, Args&&... args)
		{
			Critical(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		// --------Core--------------------------------------
		SHM_API static void InfoCore(const std::string& text);
		template<typename... Args>
		static void InfoCore(std::string_view fmtStr, Args&&... args)
		{
			InfoCore(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void WarningCore(const std::string& text);
		template<typename... Args>
		static void WarningCore(std::string_view fmtStr, Args&&... args)
		{
			WarningCore(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void ErrorCore(const std::string& text);
		template<typename... Args>
		static void ErrorCore(std::string_view fmtStr, Args&&... args)
		{
			ErrorCore(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void TraceCore(const std::string& text);
		template<typename... Args>
		static void TraceCore(std::string_view fmtStr, Args&&... args)
		{
			TraceCore(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

		SHM_API static void CriticalCore(const std::string& text);
		template<typename... Args>
		static void CriticalCore(std::string_view fmtStr, Args&&... args)
		{
			CriticalCore(std::vformat(fmtStr, std::make_format_args(std::forward<Args>(args)...)));
		}

	};

}