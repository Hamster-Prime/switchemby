#pragma once

#include <string>

namespace emby {
namespace utils {

class TimeUtils {
public:
    static long secondsToTicks(double seconds);
    static double ticksToSeconds(long ticks);
    static std::string formatDuration(long ticks);
};

} // namespace utils
} // namespace emby
