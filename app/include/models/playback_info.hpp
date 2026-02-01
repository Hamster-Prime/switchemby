#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct MediaSource {
    std::string id;
    std::string path;
    std::string container;
    long bitrate;
    bool supportsDirectPlay;
    bool supportsDirectStream;
    bool supportsTranscoding;

    static MediaSource fromJson(const nlohmann::json& j) {
        MediaSource source;
        source.id = j.value("Id", "");
        source.path = j.value("Path", "");
        source.container = j.value("Container", "");
        source.bitrate = j.value("Bitrate", 0L);
        source.supportsDirectPlay = j.value("SupportsDirectPlay", false);
        source.supportsDirectStream = j.value("SupportsDirectStream", false);
        source.supportsTranscoding = j.value("SupportsTranscoding", true);
        return source;
    }
};

struct PlaybackInfo {
    std::string itemId;
    std::vector<MediaSource> mediaSources;
    std::string playSessionId;

    static PlaybackInfo fromJson(const nlohmann::json& j) {
        PlaybackInfo info;
        info.itemId = j.value("ItemId", "");
        info.playSessionId = j.value("PlaySessionId", "");

        if (j.contains("MediaSources") && j["MediaSources"].is_array()) {
            for (const auto& source : j["MediaSources"]) {
                info.mediaSources.push_back(MediaSource::fromJson(source));
            }
        }

        return info;
    }
};

} // namespace models
} // namespace emby
