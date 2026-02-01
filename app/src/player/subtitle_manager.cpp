#include "player/subtitle_manager.hpp"

namespace emby {
namespace player {

SubtitleManager::SubtitleManager() : currentIndex_(-1) {
}

SubtitleManager::~SubtitleManager() {
}

void SubtitleManager::setSubtitles(const std::vector<Subtitle>& subtitles) {
    subtitles_ = subtitles;
    currentIndex_ = -1;
}

void SubtitleManager::selectSubtitle(int index) {
    if (index >= 0 && index < static_cast<int>(subtitles_.size())) {
        currentIndex_ = index;
    }
}

void SubtitleManager::disableSubtitle() {
    currentIndex_ = -1;
}

} // namespace player
} // namespace emby
