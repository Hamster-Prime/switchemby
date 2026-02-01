#pragma once

#include <borealis.hpp>

namespace emby {
namespace tab {

class SearchTab : public brls::Box {
public:
    SearchTab();
    ~SearchTab();

private:
    void setupUI();
};

} // namespace tab
} // namespace emby
