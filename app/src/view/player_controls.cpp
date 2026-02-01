#include "view/player_controls.hpp"

namespace emby {
namespace view {

PlayerControls::PlayerControls() {
    // Set horizontal layout
    this->setAxis(brls::Axis::ROW);
    this->setAlignItems(brls::AlignItems::CENTER);
    this->setPadding(20, 20, 20, 20);

    // Create play/pause button
    playPauseButton_ = new brls::Button();
    playPauseButton_->setLabel("Play");
    playPauseButton_->setWidth(100);
    this->addView(playPauseButton_);

    // Create seek bar
    seekBar_ = new brls::Slider();
    seekBar_->setProgress(0);
    seekBar_->setGrow(1.0f);
    seekBar_->setMargins(10, 0, 10, 0);
    this->addView(seekBar_);

    // Create time label
    timeLabel_ = new brls::Label();
    timeLabel_->setText("00:00 / 00:00");
    timeLabel_->setWidth(150);
    this->addView(timeLabel_);
}

PlayerControls::~PlayerControls() {
}

void PlayerControls::setPosition(double position) {
    if (seekBar_) {
        seekBar_->setProgress(position);
    }
}

void PlayerControls::setDuration(double duration) {
    // Duration is stored for time label formatting
    // Will be used together with position in setPosition
}

void PlayerControls::setPaused(bool paused) {
    if (playPauseButton_) {
        playPauseButton_->setLabel(paused ? "Play" : "Pause");
    }
}

} // namespace view
} // namespace emby
