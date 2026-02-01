#pragma once

#include <borealis.hpp>

namespace emby {
namespace tab {

class SettingsTab : public brls::Box {
public:
    SettingsTab();
    ~SettingsTab();

private:
    void setupUI();
};

} // namespace tab
} // namespace emby
