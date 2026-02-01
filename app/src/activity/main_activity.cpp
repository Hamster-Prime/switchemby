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
    tabFrame->addTab("Home", new tab::HomeTab());
    tabFrame->addTab("Library", new tab::LibraryTab());
    tabFrame->addTab("Search", new tab::SearchTab());
    tabFrame->addTab("Settings", new tab::SettingsTab());

    // Set as content view
    this->setContentView(tabFrame);
}

} // namespace activity
} // namespace emby
