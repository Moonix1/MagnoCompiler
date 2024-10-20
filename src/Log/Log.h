#pragma once

#include <memory>

#include <spdlog/spdlog.h>

namespace MagnoCompiler {

	class Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

#define TRACE(...)    ::MagnoCompiler::Log::GetLogger()->trace(__VA_ARGS__)
#define INFO(...)     ::MagnoCompiler::Log::GetLogger()->info(__VA_ARGS__)
#define WARN(...)     ::MagnoCompiler::Log::GetLogger()->warn(__VA_ARGS__)
#define ERROR(...)    ::MagnoCompiler::Log::GetLogger()->error(__VA_ARGS__)