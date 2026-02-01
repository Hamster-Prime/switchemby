#include "view/subtitle_selector.hpp"

namespace emby {
namespace view {

SubtitleSelector::SubtitleSelector() : selectedIndex_(-1) {
}

SubtitleSelector::~SubtitleSelector() {
}

void SubtitleSelector::setOptions(const std::vector<SubtitleOption>& options) {
    options_ = options;
}

void SubtitleSelector::setSelectedIndex(int index) {
    selectedIndex_ = index;
}

} // namespace view
} // namespace emby
