#pragma once

#include <borealis.hpp>

namespace emby {
namespace activity {

class ServerList : public brls::Activity {
public:
    ServerList();
    ~ServerList();

    void onContentAvailable() override;

private:
    void setupUI();
};

} // namespace activity
} // namespace emby
