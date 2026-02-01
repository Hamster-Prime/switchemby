#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct Server {
    std::string id;
    std::string name;
    std::string url;
    std::string version;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Server, id, name, url, version)
};

} // namespace models
} // namespace emby
