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
    // Create vertical layout
    brls::Box* container = new brls::Box();
    container->setAxis(brls::Axis::COLUMN);
    container->setGrow(1.0f);
    container->setPadding(40, 40, 40, 40);

    // Title
    brls::Label* title = new brls::Label();
    title->setText("Login to Emby");
    title->setFontSize(28);
    title->setMargins(0, 0, 0, 30);
    container->addView(title);

    // Login button
    brls::Button* loginButton = new brls::Button();
    loginButton->setLabel("Login");
    container->addView(loginButton);

    this->setContentView(container);
}

void LoginActivity::handleLogin() {
    // TODO: Implement login logic
}

} // namespace activity
} // namespace emby
