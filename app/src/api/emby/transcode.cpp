#include "api/emby/transcode.hpp"

namespace emby {
namespace transcode {

std::string TranscodeParams::toQueryString() const {
    std::ostringstream oss;
    oss << "VideoCodec=" << videoCodec
        << "&AudioCodec=" << audioCodec
        << "&Container=" << container
        << "&MaxWidth=" << maxWidth
        << "&MaxHeight=" << maxHeight
        << "&VideoBitrate=" << videoBitrate
        << "&AudioBitrate=" << audioBitrate
        << "&AudioChannels=" << audioChannels;
    return oss.str();
}

std::string buildStreamUrl(const std::string& baseUrl,
                          const std::string& itemId,
                          const TranscodeParams& params) {
    std::string url = baseUrl;
    if (url.back() == '/') url.pop_back();
    url += "/Videos/" + itemId + "/stream?" + params.toQueryString();
    return url;
}

} // namespace transcode
} // namespace emby
