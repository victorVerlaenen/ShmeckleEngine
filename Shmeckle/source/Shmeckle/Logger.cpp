#include "shmpch.h"

#include "Logger.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Shmeckle
{
	// ------- Impl ----------------------------------------------
	std::unique_ptr<Logger::Impl> Logger::impl_{ nullptr };

	class Logger::Impl
	{
	public:
		static void Initialize()
		{
			spdlog::set_pattern("%^[%T] %n: %v%$");

			sCoreLogger_ = spdlog::stdout_color_mt("SHMECKLE");
			sCoreLogger_->set_level(spdlog::level::trace);

			sClientLogger_ = spdlog::stdout_color_mt("APPLICATION");
			sClientLogger_->set_level(spdlog::level::trace);
		}

		static void Trace(const std::string& text)
		{
			sClientLogger_->trace(text);
		}
		static void Info(const std::string& text)
		{
			sClientLogger_->info(text);
		}
		static void Warning(const std::string& text)
		{
			sClientLogger_->warn(text);
		}
		static void Error(const std::string& text)
		{
			sClientLogger_->error(text);
		}
		static void Critical(const std::string& text)
		{
			sClientLogger_->critical(text);
		}

		static void TraceCore(const std::string& text)
		{
			sCoreLogger_->trace(text);
		}
		static void InfoCore(const std::string& text)
		{
			sCoreLogger_->info(text);
		}
		static void WarningCore(const std::string& text)
		{
			sCoreLogger_->warn(text);
		}
		static void ErrorCore(const std::string& text)
		{
			sCoreLogger_->error(text);
		}
		static void CriticalCore(const std::string& text)
		{
			sCoreLogger_->critical(text);
		}

	private:
		static inline std::shared_ptr<spdlog::logger> sCoreLogger_{ nullptr };
		static inline std::shared_ptr<spdlog::logger> sClientLogger_{ nullptr };
	};


	// ------- Logger --------------------------------------------
	void Logger::Initialize()
	{
		impl_ = std::make_unique<Impl>();
		impl_->Initialize();
	}

	void Logger::Trace(const std::string& text)
	{
		impl_->Trace(text);
	}
	void Logger::Info(const std::string& text)
	{
		impl_->Info(text);
	}
	void Logger::Warning(const std::string& text)
	{
		impl_->Warning(text);
	}
	void Logger::Error(const std::string& text)
	{
		impl_->Error(text);
	}
	void Logger::Critical(const std::string& text)
	{
		impl_->Critical(text);
	}

	void Logger::TraceCore(const std::string& text)
	{
		impl_->TraceCore(text);
	}
	void Logger::InfoCore(const std::string& text)
	{
		impl_->InfoCore(text);
	}
	void Logger::WarningCore(const std::string& text)
	{
		impl_->WarningCore(text);
	}
	void Logger::ErrorCore(const std::string& text)
	{
		impl_->ErrorCore(text);
	}
	void Logger::CriticalCore(const std::string& text)
	{
		impl_->CriticalCore(text);
	}

}