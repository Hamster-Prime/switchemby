#pragma once

#include <mpv/client.h>
#include <string>
#include <functional>

namespace emby {
namespace player {

// MPV event callback
using EventCallback = std::function<void(mpv_event*)>;

// MPV core wrapper
class MpvCore {
public:
    MpvCore();
    ~MpvCore();

    // Initialize MPV
    bool initialize();

    // Command execution
    int command(const char** args);
    int commandString(const char* cmd);

    // Property management
    int setProperty(const char* name, mpv_format format, void* data);
    int getProperty(const char* name, mpv_format format, void* data) const;

    // Event handling
    void setEventCallback(EventCallback callback);
    void processEvents();

    // Get raw handle
    mpv_handle* getHandle() { return mpv_; }

private:
    mpv_handle* mpv_;
    EventCallback eventCallback_;
};

} // namespace player
} // namespace emby
