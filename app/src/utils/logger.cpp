#include "utils/logger.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace emby {
namespace utils {

Logger::Logger() : minLevel_(LogLevel::INFO) {
}

Logger::~Logger() {
    if (logFile_.is_open()) {
        logFile_.close();
    }
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::setLogLevel(LogLevel level) {
    minLevel_ = level;
}

void Logger::setLogFile(const std::string& path) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (logFile_.is_open()) {
        logFile_.close();
    }
    logFilePath_ = path;
    logFile_.open(path, std::ios::app);
}

void Logger::debug(const std::string& message) {
    log(LogLevel::DEBUG, message);
}

void Logger::info(const std::string& message) {
    log(LogLevel::INFO, message);
}

void Logger::warning(const std::string& message) {
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::ERROR, message);
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level < minLevel_) return;

    std::lock_guard<std::mutex> lock(mutex_);

    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
        << " [" << levelToString(level) << "] " << message;

    std::string logLine = oss.str();

    std::cout << logLine << std::endl;

    if (logFile_.is_open()) {
        logFile_ << logLine << std::endl;
        logFile_.flush();
    }
}

std::string Logger::levelToString(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

} // namespace utils
} // namespace emby
