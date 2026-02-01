#pragma once

#include <string>
#include <functional>
#include <nlohmann/json.hpp>

namespace emby {
namespace auth {

using json = nlohmann::json;

// Authentication request
struct LoginRequest {
    std::string username;
    std::string password;

    json toJson() const {
        return {
            {"Username", username},
            {"Pw", password}
        };
    }
};

// Authentication response
struct LoginResponse {
    std::string userId;
    std::string accessToken;
    std::string serverId;

    static LoginResponse fromJson(const json& j) {
        LoginResponse resp;
        resp.userId = j.value("User", json::object()).value("Id", "");
        resp.accessToken = j.value("AccessToken", "");
        resp.serverId = j.value("ServerId", "");
        return resp;
    }
};

} // namespace auth
} // namespace emby
