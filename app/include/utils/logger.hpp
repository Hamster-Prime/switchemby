#pragma once

#include <string>
#include <fstream>
#include <mutex>

namespace emby {
namespace utils {

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    static Logger& getInstance();

    void setLogLevel(LogLevel level);
    void setLogFile(const std::string& path);

    void debug(const std::string& message);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);

private:
    Logger();
    ~Logger();

    void log(LogLevel level, const std::string& message);
    std::string levelToString(LogLevel level) const;

    LogLevel minLevel_;
    std::string logFilePath_;
    std::ofstream logFile_;
    std::mutex mutex_;
};

} // namespace utils
} // namespace emby
