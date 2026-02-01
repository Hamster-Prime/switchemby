#pragma once

#include <borealis.hpp>

namespace emby {
namespace tab {

class HomeTab : public brls::Box {
public:
    HomeTab();
    ~HomeTab();

    void loadContent();

private:
    void setupUI();
};

} // namespace tab
} // namespace emby
