#include "view/media_grid.hpp"

namespace emby {
namespace view {

MediaGrid::MediaGrid() {
    // Set grid layout properties
    this->setAxis(brls::Axis::ROW);
    this->setJustifyContent(brls::JustifyContent::FLEX_START);
    this->setAlignItems(brls::AlignItems::FLEX_START);
    this->setGrow(1.0f);
}

MediaGrid::~MediaGrid() {
}

void MediaGrid::addItem(brls::View* item) {
    if (item) {
        items_.push_back(item);
        this->addView(item);
    }
}

void MediaGrid::clear() {
    // Remove all child views
    for (auto* item : items_) {
        this->removeView(item);
    }
    items_.clear();
}

} // namespace view
} // namespace emby
