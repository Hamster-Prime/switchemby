#include "utils/time_utils.hpp"
#include <sstream>
#include <iomanip>

namespace emby {
namespace utils {

long TimeUtils::secondsToTicks(double seconds) {
    return static_cast<long>(seconds * 10000000);
}

double TimeUtils::ticksToSeconds(long ticks) {
    return static_cast<double>(ticks) / 10000000.0;
}

std::string TimeUtils::formatDuration(long ticks) {
    long totalSeconds = ticks / 10000000;
    long hours = totalSeconds / 3600;
    long minutes = (totalSeconds % 3600) / 60;
    long seconds = totalSeconds % 60;

    std::ostringstream oss;
    if (hours > 0) {
        oss << hours << ":" << std::setfill('0') << std::setw(2) << minutes
            << ":" << std::setw(2) << seconds;
    } else {
        oss << minutes << ":" << std::setfill('0') << std::setw(2) << seconds;
    }
    return oss.str();
}

} // namespace utils
} // namespace emby
