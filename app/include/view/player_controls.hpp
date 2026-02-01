#pragma once

#include <borealis.hpp>

namespace emby {
namespace view {

class PlayerControls : public brls::Box {
public:
    PlayerControls();
    ~PlayerControls();

    void setPosition(double position);
    void setDuration(double duration);
    void setPaused(bool paused);

private:
    // brls::Slider* seekBar_;  // TODO: Slider not available in current borealis version
    brls::Label* timeLabel_;
    brls::Button* playPauseButton_;
};

} // namespace view
} // namespace emby
