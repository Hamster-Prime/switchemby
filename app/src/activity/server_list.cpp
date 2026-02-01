#include "activity/server_list.hpp"

namespace emby {
namespace activity {

ServerList::ServerList() {
}

ServerList::~ServerList() {
}

void ServerList::onContentAvailable() {
    setupUI();
}

void ServerList::setupUI() {
    // Create vertical layout
    brls::Box* container = new brls::Box();
    container->setAxis(brls::Axis::COLUMN);
    container->setGrow(1.0f);
    container->setPadding(20, 20, 20, 20);

    // Title
    brls::Label* title = new brls::Label();
    title->setText("Emby Servers");
    title->setFontSize(28);
    title->setMargins(0, 0, 0, 20);
    container->addView(title);

    // Add server button
    brls::Button* addButton = new brls::Button();
    addButton->setText("Add Server");
    container->addView(addButton);

    this->setContentView(container);
}

} // namespace activity
} // namespace emby
