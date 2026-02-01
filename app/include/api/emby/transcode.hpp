#pragma once

#include <string>
#include <sstream>

namespace emby {
namespace transcode {

// Transcode parameters optimized for Switch
struct TranscodeParams {
    std::string videoCodec = "h264";
    std::string audioCodec = "aac";
    std::string container = "mp4";
    int maxWidth = 1920;
    int maxHeight = 1080;
    int videoBitrate = 8000000;  // 8 Mbps
    int audioBitrate = 192000;   // 192 Kbps
    int audioChannels = 2;

    std::string toQueryString() const;
};

// Build stream URL
std::string buildStreamUrl(const std::string& baseUrl,
                          const std::string& itemId,
                          const TranscodeParams& params);

} // namespace transcode
} // namespace emby
