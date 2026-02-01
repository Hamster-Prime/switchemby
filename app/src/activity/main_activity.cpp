#include "activity/main_activity.hpp"
#include "tab/home_tab.hpp"
#include "tab/library_tab.hpp"
#include "tab/search_tab.hpp"
#include "tab/settings_tab.hpp"

namespace emby {
namespace activity {

MainActivity::MainActivity() {
}

MainActivity::~MainActivity() {
}

void MainActivity::onContentAvailable() {
    setupTabs();
}

void MainActivity::setupTabs() {
    // Create tab frame
    brls::TabFrame* tabFrame = new brls::TabFrame();

    // Add tabs
    tabFrame->addTab("Home", []() { return new tab::HomeTab(); });
    tabFrame->addTab("Library", []() { return new tab::LibraryTab(); });
    tabFrame->addTab("Search", []() { return new tab::SearchTab(); });
    tabFrame->addTab("Settings", []() { return new tab::SettingsTab(); });

    // Set as content view
    this->setContentView(tabFrame);
}

} // namespace activity
} // namespace emby
