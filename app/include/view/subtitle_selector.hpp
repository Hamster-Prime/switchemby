#pragma once

#include <borealis.hpp>
#include <vector>
#include <string>

namespace emby {
namespace view {

struct SubtitleOption {
    int index;
    std::string language;
    std::string displayTitle;
};

class SubtitleSelector : public brls::Box {
public:
    SubtitleSelector();
    ~SubtitleSelector();

    void setOptions(const std::vector<SubtitleOption>& options);
    void setSelectedIndex(int index);

private:
    std::vector<SubtitleOption> options_;
    int selectedIndex_;
};

} // namespace view
} // namespace emby
