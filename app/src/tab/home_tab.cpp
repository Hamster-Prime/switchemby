#include "tab/home_tab.hpp"

namespace emby {
namespace tab {

HomeTab::HomeTab() {
    setupUI();
}

HomeTab::~HomeTab() {
}

void HomeTab::setupUI() {
    // Set vertical layout
    this->setAxis(brls::Axis::COLUMN);
    this->setGrow(1.0f);
    this->setPadding(20, 20, 20, 20);

    // Create title label
    brls::Label* title = new brls::Label();
    title->setText("Home");
    title->setFontSize(28);
    title->setMargins(0, 0, 0, 20);
    this->addView(title);

    // Content will be loaded dynamically in loadContent()
}

void HomeTab::loadContent() {
    // Create sections for different content types

    // Continue Watching section
    brls::Label* continueLabel = new brls::Label();
    continueLabel->setText("Continue Watching");
    continueLabel->setFontSize(20);
    continueLabel->setMargins(0, 10, 0, 10);
    this->addView(continueLabel);

    // Latest section
    brls::Label* latestLabel = new brls::Label();
    latestLabel->setText("Latest Added");
    latestLabel->setFontSize(20);
    latestLabel->setMargins(0, 20, 0, 10);
    this->addView(latestLabel);

    // TODO: Load actual content from Emby API
}

} // namespace tab
} // namespace emby
