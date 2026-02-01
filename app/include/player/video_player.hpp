#pragma once

#include "player/mpv_core.hpp"
#include <string>
#include <functional>

namespace emby {
namespace player {

enum class PlayerState {
    IDLE,
    LOADING,
    PLAYING,
    PAUSED,
    STOPPED
};

class VideoPlayer {
public:
    VideoPlayer();
    ~VideoPlayer();

    bool initialize();
    void play(const std::string& url);
    void pause();
    void resume();
    void stop();
    void seek(double seconds);

    PlayerState getState() const { return state_; }
    double getPosition() const;
    double getDuration() const;

private:
    MpvCore mpvCore_;
    PlayerState state_;
};

} // namespace player
} // namespace emby
