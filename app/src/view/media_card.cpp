#include "view/media_card.hpp"

namespace emby {
namespace view {

#include "view/media_card.hpp"
#include "utils/image_loader.hpp"

namespace emby {
namespace view {

MediaCard::MediaCard() {
    // Set card dimensions
    this->setWidth(200);
    this->setHeight(320);
    this->setMargins(10, 10, 10, 10);

    // Create image component
    image_ = new brls::Image();
    image_->setWidth(200);
    image_->setHeight(280);
    image_->setScaleType(brls::ImageScaleType::SCALE_TO_FILL);
    this->addView(image_);

    // Create title label
    title_ = new brls::Label();
    title_->setFontSize(16);
    title_->setHeight(30);
    title_->setMargins(5, 5, 5, 5);
    this->addView(title_);

    // TODO: ProgressBar not available in current borealis version
    // Create progress bar (initially hidden)
    // progress_ = new brls::ProgressBar();
    // progress_->setHeight(4);
    // progress_->setProgress(0);
    // progress_->setVisibility(brls::Visibility::GONE);
    // this->addView(progress_);
}

MediaCard::~MediaCard() {
}

void MediaCard::setTitle(const std::string& title) {
    if (title_) {
        title_->setText(title);
    }
}

void MediaCard::setImageUrl(const std::string& url) {
    if (image_ && !url.empty()) {
        // Load image asynchronously
        utils::ImageLoader::getInstance().loadAsync(url,
            [this](const std::string& path) {
                if (image_) {
                    image_->setImageFromFile(path);
                }
            }
        );
    }
}

void MediaCard::setProgress(float progress) {
    // TODO: ProgressBar not available in current borealis version
    // if (progress_) {
    //     if (progress > 0 && progress < 1.0f) {
    //         progress_->setProgress(progress);
    //         progress_->setVisibility(brls::Visibility::VISIBLE);
    //     } else {
    //         progress_->setVisibility(brls::Visibility::GONE);
    //     }
    // }
    (void)progress;  // Suppress unused parameter warning
}

} // namespace view
} // namespace emby
