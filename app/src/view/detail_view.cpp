#include "view/detail_view.hpp"

namespace emby {
namespace view {

DetailView::DetailView() {
    // Set vertical layout
    this->setAxis(brls::Axis::COLUMN);
    this->setGrow(1.0f);
    this->setPadding(20, 20, 20, 20);

    // Create title label
    title_ = new brls::Label();
    title_->setFontSize(32);
    title_->setMargins(0, 0, 0, 20);
    this->addView(title_);

    // Create overview label
    overview_ = new brls::Label();
    overview_->setFontSize(18);
    overview_->setMaxLines(10);
    this->addView(overview_);
}

DetailView::~DetailView() {
}

void DetailView::setTitle(const std::string& title) {
    if (title_) {
        title_->setText(title);
    }
}

void DetailView::setOverview(const std::string& overview) {
    if (overview_) {
        overview_->setText(overview);
    }
}

} // namespace view
} // namespace emby
