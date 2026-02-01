#pragma once

#include <borealis.hpp>
#include <vector>
#include <string>

namespace emby {
namespace view {

class MediaCard : public brls::Box {
public:
    MediaCard();
    ~MediaCard();

    void setTitle(const std::string& title);
    void setImageUrl(const std::string& url);
    void setProgress(float progress);

private:
    brls::Image* image_;
    brls::Label* title_;
    // brls::ProgressBar* progress_;  // TODO: ProgressBar not available in current borealis version
};

} // namespace view
} // namespace emby
