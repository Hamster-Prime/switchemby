#include "player/video_player.hpp"

namespace emby {
namespace player {

VideoPlayer::VideoPlayer() : state_(PlayerState::IDLE) {
}

VideoPlayer::~VideoPlayer() {
    stop();
}

bool VideoPlayer::initialize() {
    return mpvCore_.initialize();
}

void VideoPlayer::play(const std::string& url) {
    const char* cmd[] = {"loadfile", url.c_str(), nullptr};
    mpvCore_.command(cmd);
    state_ = PlayerState::LOADING;
}

void VideoPlayer::pause() {
    int flag = 1;
    mpvCore_.setProperty("pause", MPV_FORMAT_FLAG, &flag);
    state_ = PlayerState::PAUSED;
}

void VideoPlayer::resume() {
    int flag = 0;
    mpvCore_.setProperty("pause", MPV_FORMAT_FLAG, &flag);
    state_ = PlayerState::PLAYING;
}

void VideoPlayer::stop() {
    const char* cmd[] = {"stop", nullptr};
    mpvCore_.command(cmd);
    state_ = PlayerState::STOPPED;
}

void VideoPlayer::seek(double seconds) {
    mpvCore_.setProperty("time-pos", MPV_FORMAT_DOUBLE, &seconds);
}

double VideoPlayer::getPosition() const {
    double pos = 0;
    mpvCore_.getProperty("time-pos", MPV_FORMAT_DOUBLE, &pos);
    return pos;
}

double VideoPlayer::getDuration() const {
    double dur = 0;
    mpvCore_.getProperty("duration", MPV_FORMAT_DOUBLE, &dur);
    return dur;
}

} // namespace player
} // namespace emby
