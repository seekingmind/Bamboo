#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/ostream.h"

namespace Bamboo {

	class BAMBOO_API Log
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

// Core Logging Macros
#define BB_CORE_TRACE(...)    Bamboo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BB_CORE_INFO(...)     Bamboo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BB_CORE_WARN(...)	  Bamboo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BB_CORE_ERROR(...)	  Bamboo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BB_CORE_FATAL(...)	  Bamboo::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define BB_TRACE(...)	Bamboo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BB_INFO(...)	Bamboo::Log::GetClientLogger()->info(__VA_ARGS__)
#define BB_WARN(...)	Bamboo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BB_ERROR(...)	Bamboo::Log::GetClientLogger()->error(__VA_ARGS__)
#define BB_FATAL(...)	Bamboo::Log::GetClientLogger()->critical(__VA_ARGS__)
