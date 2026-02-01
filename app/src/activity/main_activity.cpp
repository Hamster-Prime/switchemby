#include "activity/main_activity.hpp"

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
    // TODO: Setup tab navigation
}

} // namespace activity
} // namespace emby
