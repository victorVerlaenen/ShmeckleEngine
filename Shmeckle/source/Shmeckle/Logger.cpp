#include "shmpch.h"

#include <format>

#include "Logger.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Shmeckle
{

	// Logger pointer to implemention
	class Logger::LoggerPimpl
	{
	public:
		static void Initialize();

		inline static void Trace(const std::string& formatedString) { sClientLogger_->trace(formatedString); }
		inline static void Info(const std::string& formatedString) { sClientLogger_->info(formatedString); }
		inline static void Warning(const std::string& formatedString) { sClientLogger_->warn(formatedString); }
		inline static void Error(const std::string& formatedString) { sClientLogger_->error(formatedString); }
		inline static void Critical(const std::string& formatedString) { sClientLogger_->critical(formatedString); }

		inline static void TraceCore(const std::string& formatedString) { sCoreLogger_->trace(formatedString); }
		inline static void InfoCore(const std::string& formatedString) { sCoreLogger_->info(formatedString); }
		inline static void WarningCore(const std::string& formatedString) { sCoreLogger_->warn(formatedString); }
		inline static void ErrorCore(const std::string& formatedString) { sCoreLogger_->error(formatedString); }
		inline static void CriticalCore(const std::string& formatedString) { sCoreLogger_->critical(formatedString); }

	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger_;
		static std::shared_ptr<spdlog::logger> sClientLogger_;
	};

	void Logger::LoggerPimpl::Initialize()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		sCoreLogger_ = spdlog::stdout_color_mt("SHMECKLE");
		sCoreLogger_->set_level(spdlog::level::trace);

		sClientLogger_ = spdlog::stdout_color_mt("APPLICATION");
		sClientLogger_->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger> Logger::LoggerPimpl::sCoreLogger_;
	std::shared_ptr<spdlog::logger> Logger::LoggerPimpl::sClientLogger_;

	// Logger
	std::unique_ptr<Logger::LoggerPimpl> Logger::supLoggerPimpl_;

	void Logger::Initialize()
	{
		supLoggerPimpl_ = std::make_unique<LoggerPimpl>();
		supLoggerPimpl_->Initialize();
	}

	void Logger::Trace(const std::string& formatedString)
	{
		supLoggerPimpl_->Trace(formatedString);
	}

	void Logger::Info(const std::string& formatedString)
	{
		supLoggerPimpl_->Info(formatedString);
	}

	void Logger::Warning(const std::string& formatedString)
	{
		supLoggerPimpl_->Warning(formatedString);
	}

	void Logger::Error(const std::string& formatedString)
	{
		supLoggerPimpl_->Error(formatedString);
	}

	void Logger::Critical(const std::string& formatedString)
	{
		supLoggerPimpl_->Critical(formatedString);
	}

	void Logger::TraceCore(const std::string& formatedString)
	{
		supLoggerPimpl_->TraceCore(formatedString);
	}

	void Logger::InfoCore(const std::string& formatedString)
	{
		supLoggerPimpl_->InfoCore(formatedString);
	}

	void Logger::WarningCore(const std::string& formatedString)
	{
		supLoggerPimpl_->WarningCore(formatedString);
	}

	void Logger::ErrorCore(const std::string& formatedString)
	{
		supLoggerPimpl_->ErrorCore(formatedString);
	}

	void Logger::CriticalCore(const std::string& formatedString)
	{
		supLoggerPimpl_->CriticalCore(formatedString);
	}

}