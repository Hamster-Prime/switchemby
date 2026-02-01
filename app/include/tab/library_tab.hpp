#pragma once

#include <borealis.hpp>

namespace emby {
namespace tab {

class LibraryTab : public brls::Box {
public:
    LibraryTab();
    ~LibraryTab();

    void loadLibraries();

private:
    void setupUI();
};

} // namespace tab
} // namespace emby
