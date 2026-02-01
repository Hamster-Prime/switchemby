#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct User {
    std::string id;
    std::string name;
    std::string serverId;
    bool hasPassword;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, id, name, serverId, hasPassword)
};

} // namespace models
} // namespace emby
