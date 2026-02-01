#pragma once

#include <borealis.hpp>
#include <vector>

namespace emby {
namespace view {

class MediaGrid : public brls::Box {
public:
    MediaGrid();
    ~MediaGrid();

    void addItem(brls::View* item);
    void clear();

private:
    std::vector<brls::View*> items_;
};

} // namespace view
} // namespace emby
