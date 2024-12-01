#pragma once
#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"

namespace shmeckle
{
	class SHMECKLE_API Logger
	{
	public:
		static void Initialize();
		static void CleanUp();

		// Convenience functions for core logger
		static inline void CoreTrace(const std::string& text) { s_CoreLogger->trace(text); }
		template <typename... Args>
		static inline void CoreTrace(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->trace(fmt, std::forward<Args>(args)...);
		}
		static inline void CoreInfo(const std::string& text) { s_CoreLogger->info(text); }
		template <typename... Args>
 		static inline void CoreInfo(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->info(fmt, std::forward<Args>(args)...);
		}
		static inline void CoreWarning(const std::string& text) { s_CoreLogger->warn(text); }
		template <typename... Args>
		static inline void CoreWarning(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->warn(fmt, std::forward<Args>(args)...);
		}
		static inline void CoreError(const std::string& text) { s_CoreLogger->error(text); }
		template <typename... Args>
		static inline void CoreError(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->error(fmt, std::forward<Args>(args)...);
		}
		static inline void CoreCritical(const std::string& text) { s_CoreLogger->critical(text); }
		template <typename... Args>
		static inline void CoreCritical(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->critical(fmt, std::forward<Args>(args)...);
		}

		// Convenience functions for client logger
		static inline void Trace(const std::string& text) { s_ClientLogger->trace(text); }
		template <typename... Args>
		static inline void Trace(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->trace(fmt, std::forward<Args>(args)...);
		}
		static inline void Info(const std::string& text) { s_ClientLogger->info(text); }
		template <typename... Args>
		static inline void Info(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->info(fmt, std::forward<Args>(args)...);
		}
		static inline void Warning(const std::string& text) { s_ClientLogger->warn(text); }
		template <typename... Args>
		static inline void Warning(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->warn(fmt, std::forward<Args>(args)...);
		}
		static inline void Error(const std::string& text) { s_ClientLogger->error(text); }
		template <typename... Args>
		static inline void Error(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->error(fmt, std::forward<Args>(args)...);
		}
		static inline void Critical(const std::string& text) { s_ClientLogger->critical(text); }
		template <typename... Args>
		static inline void Critical(spdlog::format_string_t<Args...> fmt, Args &&...args) {
			s_CoreLogger->critical(fmt, std::forward<Args>(args)...);
		}

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

	// Forward declarations for fmt
	class Event;
}

// Tell fmt how to format user definedd types
template <>
struct fmt::formatter<shmeckle::Event> : fmt::ostream_formatter {};