#include <common/log/bg_log.h>

namespace BG
{
	Log g_log_context;
	Log::Log()
	{
		m_log_type_map[LOG_TYPE_TRACE] = spdlog::level::trace;
		m_log_type_map[LOG_TYPE_DEBUG] = spdlog::level::debug;
		m_log_type_map[LOG_TYPE_INFO] = spdlog::level::info;
		m_log_type_map[LOG_TYPE_WARNING] = spdlog::level::warn;
		m_log_type_map[LOG_TYPE_ERROR] = spdlog::level::err;
		m_log_type_map[LOG_TYPE_CRITICAL] = spdlog::level::critical;
	}
	Log::~Log()
	{
	}
	void Log::initialize(LOG_TYPE log_type, const BGString& app_name)
	{
		auto spd_log_type = m_log_type_map[log_type];
		BGString log_name = app_name + "-" + std::to_string(getpid()) + "-%Y-%m-%d-%H-%M-%S-log.txt";
		m_logger = spdlog::rotating_logger_mt<spdlog::async_factory>("logger", log_name, 1024 * 1024 * 5, 10);
		spdlog::set_level(spd_log_type);
		spdlog::set_pattern("[%n %P %Y-%m-%d %H:%M:%S][%^%l%$] %v");
	}
	void Log::end()
	{
		spdlog::shutdown();
	}
}