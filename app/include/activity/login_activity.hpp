#pragma once

#include <borealis.hpp>

namespace emby {
namespace activity {

class LoginActivity : public brls::Activity {
public:
    LoginActivity();
    ~LoginActivity();

    void onContentAvailable() override;

private:
    void setupUI();
    void handleLogin();
};

} // namespace activity
} // namespace emby
