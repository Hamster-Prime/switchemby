#include "tab/search_tab.hpp"

namespace emby {
namespace tab {

SearchTab::SearchTab() {
    setupUI();
}

SearchTab::~SearchTab() {
}

void SearchTab::setupUI() {
    // Set vertical layout
    this->setAxis(brls::Axis::COLUMN);
    this->setGrow(1.0f);
    this->setPadding(20, 20, 20, 20);

    // Create title
    brls::Label* title = new brls::Label();
    title->setText("Search");
    title->setFontSize(28);
    title->setMargins(0, 0, 0, 20);
    this->addView(title);

    // TODO: Add search input and results
}

} // namespace tab
} // namespace emby
