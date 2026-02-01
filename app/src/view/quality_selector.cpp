#include "view/quality_selector.hpp"

namespace emby {
namespace view {

QualitySelector::QualitySelector() : selectedIndex_(-1) {
}

QualitySelector::~QualitySelector() {
}

void QualitySelector::setOptions(const std::vector<QualityOption>& options) {
    options_ = options;
}

void QualitySelector::setSelectedIndex(int index) {
    selectedIndex_ = index;
}

} // namespace view
} // namespace emby
