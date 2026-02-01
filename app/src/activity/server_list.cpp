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
}

} // namespace activity
} // namespace emby
