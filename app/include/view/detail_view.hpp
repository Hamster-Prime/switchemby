#pragma once

#include <borealis.hpp>
#include <string>

namespace emby {
namespace view {

class DetailView : public brls::Box {
public:
    DetailView();
    ~DetailView();

    void setTitle(const std::string& title);
    void setOverview(const std::string& overview);

private:
    brls::Label* title_;
    brls::Label* overview_;
};

} // namespace view
} // namespace emby
