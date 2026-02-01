#include "activity/player_activity.hpp"
#include "view/player_controls.hpp"

namespace emby {
namespace activity {

PlayerActivity::PlayerActivity() {
}

PlayerActivity::~PlayerActivity() {
}

void PlayerActivity::onContentAvailable() {
    setupUI();
}

void PlayerActivity::setupUI() {
    // Create vertical layout
    brls::Box* container = new brls::Box();
    container->setAxis(brls::Axis::COLUMN);
    container->setGrow(1.0f);

    // Video view area (placeholder)
    brls::Box* videoArea = new brls::Box();
    videoArea->setGrow(1.0f);
    container->addView(videoArea);

    // Player controls
    view::PlayerControls* controls = new view::PlayerControls();
    container->addView(controls);

    this->setContentView(container);
}

} // namespace activity
} // namespace emby
