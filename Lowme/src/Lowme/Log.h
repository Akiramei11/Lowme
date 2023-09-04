#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Lowme {

	class LOWME_API Log
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
#define LM_CORE_INFO(...)     ::Lowme::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LM_CORE_TRACE(...)    ::Lowme::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LM_CORE_WARN(...)     ::Lowme::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LM_CORE_ERROR(...)    ::Lowme::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LM_CORE_FATAL(...)    ::Lowme::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LM_TRACE(...)	      ::Lowme::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LM_INFO(...)	      ::Lowme::Log::GetClientLogger()->info(__VA_ARGS__)
#define LM_WARN(...)	      ::Lowme::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LM_ERROR(...)	      ::Lowme::Log::GetClientLogger()->error(__VA_ARGS__)
#define LM_FATAL(...)	      ::Lowme::Log::GetClientLogger()->fatal(__VA_ARGS__)
