#pragma once

#include <borealis.hpp>
#include <vector>
#include <string>

namespace emby {
namespace view {

struct QualityOption {
    int bitrate;
    std::string label;
    bool requiresTranscode;
};

class QualitySelector : public brls::Box {
public:
    QualitySelector();
    ~QualitySelector();

    void setOptions(const std::vector<QualityOption>& options);
    void setSelectedIndex(int index);

private:
    std::vector<QualityOption> options_;
    int selectedIndex_;
};

} // namespace view
} // namespace emby
