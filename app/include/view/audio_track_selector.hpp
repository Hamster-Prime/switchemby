#pragma once

#include <borealis.hpp>
#include <vector>
#include <string>

namespace emby {
namespace view {

struct AudioTrackOption {
    int index;
    std::string language;
    std::string codec;
    std::string displayTitle;
};

class AudioTrackSelector : public brls::Box {
public:
    AudioTrackSelector();
    ~AudioTrackSelector();

    void setOptions(const std::vector<AudioTrackOption>& options);
    void setSelectedIndex(int index);

private:
    std::vector<AudioTrackOption> options_;
    int selectedIndex_;
};

} // namespace view
} // namespace emby
