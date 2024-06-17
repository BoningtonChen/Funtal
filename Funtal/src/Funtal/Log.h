#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Funtal
{
	class FUNTAL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define FT_CORE_TRACE(...) ::Funtal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FT_CORE_INFO(...)  ::Funtal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FT_CORE_WARN(...)  ::Funtal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FT_CORE_ERROR(...) ::Funtal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FT_CORE_FATAL(...) ::Funtal::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FT_TRACE(...) ::Funtal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FT_INFO(...)  ::Funtal::Log::GetClientLogger()->info(__VA_ARGS__)
#define FT_WARN(...)  ::Funtal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FT_ERROR(...) ::Funtal::Log::GetClientLogger()->error(__VA_ARGS__)
#define FT_FATAL(...) ::Funtal::Log::GetClientLogger()->fatal(__VA_ARGS__)