#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct MediaItem {
    std::string id;
    std::string name;
    std::string type;
    std::string overview;
    long runTimeTicks;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(MediaItem, id, name, type, overview, runTimeTicks)
};

} // namespace models
} // namespace emby
