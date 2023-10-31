#pragma once
#include <common/type/bg_base_type.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/async.h"

namespace BG
{
	enum LOG_TYPE : int
	{
		LOG_TYPE_TRACE = 0,
		LOG_TYPE_DEBUG = 1,
		LOG_TYPE_INFO = 2,
		LOG_TYPE_WARNING = 3,
		LOG_TYPE_ERROR = 4,
		LOG_TYPE_CRITICAL = 5,
	};
	class Log
	{
	public:
		Log();
		~Log();
		void initialize(LOG_TYPE log_type, const BGString& app_name);
		void end();

	public:
		std::shared_ptr<spdlog::logger> m_logger;
	private:
		BGUnorderedMap<UInt32, spdlog::level::level_enum> m_log_type_map;
	};

	extern Log g_log_context;

#define LOG_INFO(...) g_log_context.m_logger->info(__VA_ARGS__);
#define LOG_WARNING(...) g_log_context.m_logger->warn(__VA_ARGS__);
#define LOG_ERROR(...) g_log_context.m_logger->error(__VA_ARGS__);
#define LOG_CRITICAL(...) g_log_context.m_logger->critical(__VA_ARGS__);
}

