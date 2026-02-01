#include "player/playback_state.hpp"
#include <chrono>

namespace emby {
namespace player {

PlaybackState::PlaybackState() {
}

PlaybackState::~PlaybackState() {
}

void PlaybackState::startSession(const std::string& itemId) {
    session_.itemId = itemId;
    session_.positionTicks = 0;
    session_.isPaused = false;
    session_.lastReportTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

void PlaybackState::updatePosition(long positionTicks, bool isPaused) {
    session_.positionTicks = positionTicks;
    session_.isPaused = isPaused;
    session_.lastReportTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

void PlaybackState::endSession() {
    session_ = PlaybackSession();
}

} // namespace player
} // namespace emby
