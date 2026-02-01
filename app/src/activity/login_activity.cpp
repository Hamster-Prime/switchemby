#include "activity/login_activity.hpp"

namespace emby {
namespace activity {

LoginActivity::LoginActivity() {
}

LoginActivity::~LoginActivity() {
}

void LoginActivity::onContentAvailable() {
    setupUI();
}

void LoginActivity::setupUI() {
}

void LoginActivity::handleLogin() {
}

} // namespace activity
} // namespace emby
