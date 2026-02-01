#include "activity/player_activity.hpp"

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
}

} // namespace activity
} // namespace emby
