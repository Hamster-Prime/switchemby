#pragma once

#include <borealis.hpp>

namespace emby {
namespace activity {

class MainActivity : public brls::Activity {
public:
    MainActivity();
    ~MainActivity();

    void onContentAvailable() override;

private:
    void setupTabs();
};

} // namespace activity
} // namespace emby
