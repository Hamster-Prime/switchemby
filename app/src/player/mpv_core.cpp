#include "player/mpv_core.hpp"
#include <iostream>

namespace emby {
namespace player {

MpvCore::MpvCore() : mpv_(nullptr), eventCallback_(nullptr) {
}

MpvCore::~MpvCore() {
    if (mpv_) {
        mpv_terminate_destroy(mpv_);
        mpv_ = nullptr;
    }
}

bool MpvCore::initialize() {
    mpv_ = mpv_create();
    if (!mpv_) {
        return false;
    }

    // Switch-specific configuration
#ifdef __SWITCH__
    mpv_set_option_string(mpv_, "hwdec", "auto");
    mpv_set_option_string(mpv_, "vo", "gpu");
    mpv_set_option_string(mpv_, "gpu-context", "switch");
#endif

    // Common configuration
    mpv_set_option_string(mpv_, "keep-open", "yes");
    mpv_set_option_string(mpv_, "idle", "yes");

    if (mpv_initialize(mpv_) < 0) {
        mpv_terminate_destroy(mpv_);
        mpv_ = nullptr;
        return false;
    }

    return true;
}

int MpvCore::command(const char** args) {
    return mpv_command(mpv_, args);
}

int MpvCore::commandString(const char* cmd) {
    return mpv_command_string(mpv_, cmd);
}

int MpvCore::setProperty(const char* name, mpv_format format, void* data) {
    return mpv_set_property(mpv_, name, format, data);
}

int MpvCore::getProperty(const char* name, mpv_format format, void* data) const {
    return mpv_get_property(mpv_, name, format, data);
}

void MpvCore::setEventCallback(EventCallback callback) {
    eventCallback_ = callback;
}

void MpvCore::processEvents() {
    while (mpv_) {
        mpv_event* event = mpv_wait_event(mpv_, 0);
        if (event->event_id == MPV_EVENT_NONE) {
            break;
        }
        if (eventCallback_) {
            eventCallback_(event);
        }
    }
}

} // namespace player
} // namespace emby
