#include "tab/settings_tab.hpp"

namespace emby {
namespace tab {

SettingsTab::SettingsTab() {
    setupUI();
}

SettingsTab::~SettingsTab() {
}

void SettingsTab::setupUI() {
    // Set vertical layout
    this->setAxis(brls::Axis::COLUMN);
    this->setGrow(1.0f);
    this->setPadding(20, 20, 20, 20);

    // Create title
    brls::Label* title = new brls::Label();
    title->setText("Settings");
    title->setFontSize(28);
    title->setMargins(0, 0, 0, 20);
    this->addView(title);

    // TODO: Add settings options
}

} // namespace tab
} // namespace emby
