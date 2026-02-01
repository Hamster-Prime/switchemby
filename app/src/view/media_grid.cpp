#include "view/media_grid.hpp"

namespace emby {
namespace view {

MediaGrid::MediaGrid() {
}

MediaGrid::~MediaGrid() {
}

void MediaGrid::addItem(brls::View* item) {
    items_.push_back(item);
}

void MediaGrid::clear() {
    items_.clear();
}

} // namespace view
} // namespace emby
