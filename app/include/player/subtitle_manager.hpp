#pragma once

#include <string>
#include <vector>

namespace emby {
namespace player {

struct Subtitle {
    std::string id;
    std::string language;
    std::string displayTitle;
    std::string codec;
    bool isExternal;
};

class SubtitleManager {
public:
    SubtitleManager();
    ~SubtitleManager();

    void setSubtitles(const std::vector<Subtitle>& subtitles);
    void selectSubtitle(int index);
    void disableSubtitle();

    std::vector<Subtitle> getSubtitles() const { return subtitles_; }
    int getCurrentIndex() const { return currentIndex_; }

private:
    std::vector<Subtitle> subtitles_;
    int currentIndex_;
};

} // namespace player
} // namespace emby
