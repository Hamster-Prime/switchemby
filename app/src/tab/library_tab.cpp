#include "tab/library_tab.hpp"

namespace emby {
namespace tab {

LibraryTab::LibraryTab() {
    setupUI();
}

LibraryTab::~LibraryTab() {
}

void LibraryTab::setupUI() {
    // Set vertical layout
    this->setAxis(brls::Axis::COLUMN);
    this->setGrow(1.0f);
    this->setPadding(20, 20, 20, 20);

    // Create title
    brls::Label* title = new brls::Label();
    title->setText("Library");
    title->setFontSize(28);
    title->setMargins(0, 0, 0, 20);
    this->addView(title);
}

void LibraryTab::loadLibraries() {
    // Create library sections
    brls::Label* moviesLabel = new brls::Label();
    moviesLabel->setText("Movies");
    moviesLabel->setFontSize(20);
    moviesLabel->setMargins(0, 10, 0, 10);
    this->addView(moviesLabel);

    brls::Label* showsLabel = new brls::Label();
    showsLabel->setText("TV Shows");
    showsLabel->setFontSize(20);
    showsLabel->setMargins(0, 20, 0, 10);
    this->addView(showsLabel);

    // TODO: Load actual libraries from Emby API
}

} // namespace tab
} // namespace emby
