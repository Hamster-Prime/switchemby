#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace emby {
namespace playback {

using json = nlohmann::json;

// Playback progress report
struct ProgressReport {
    std::string itemId;
    long positionTicks;
    bool isPaused;
    bool isMuted;
    int volumeLevel;

    json toJson() const {
        return {
            {"ItemId", itemId},
            {"PositionTicks", positionTicks},
            {"IsPaused", isPaused},
            {"IsMuted", isMuted},
            {"VolumeLevel", volumeLevel}
        };
    }
};

} // namespace playback
} // namespace emby
