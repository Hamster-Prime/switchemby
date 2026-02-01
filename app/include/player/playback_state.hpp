#pragma once

#include <string>
#include <functional>

namespace emby {
namespace player {

struct PlaybackSession {
    std::string itemId;
    std::string sessionId;
    long positionTicks;
    bool isPaused;
    long lastReportTime;
};

class PlaybackState {
public:
    PlaybackState();
    ~PlaybackState();

    void startSession(const std::string& itemId);
    void updatePosition(long positionTicks, bool isPaused);
    void endSession();

    PlaybackSession getCurrentSession() const { return session_; }
    bool hasActiveSession() const { return !session_.itemId.empty(); }

private:
    PlaybackSession session_;
};

} // namespace player
} // namespace emby
