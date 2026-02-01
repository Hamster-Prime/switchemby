#pragma once

#include <borealis.hpp>

namespace emby {
namespace activity {

class PlayerActivity : public brls::Activity {
public:
    PlayerActivity();
    ~PlayerActivity();

    void onContentAvailable() override;

private:
    void setupUI();
};

} // namespace activity
} // namespace emby
