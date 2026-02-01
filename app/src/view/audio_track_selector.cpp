#include "view/audio_track_selector.hpp"

namespace emby {
namespace view {

AudioTrackSelector::AudioTrackSelector() : selectedIndex_(-1) {
}

AudioTrackSelector::~AudioTrackSelector() {
}

void AudioTrackSelector::setOptions(const std::vector<AudioTrackOption>& options) {
    options_ = options;
}

void AudioTrackSelector::setSelectedIndex(int index) {
    selectedIndex_ = index;
}

} // namespace view
} // namespace emby
