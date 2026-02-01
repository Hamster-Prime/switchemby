#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace emby {
namespace utils {

class Config {
public:
    static Config& getInstance();

    bool load(const std::string& path);
    bool save(const std::string& path);

    std::string getServerUrl() const { return serverUrl_; }
    void setServerUrl(const std::string& url) { serverUrl_ = url; }

    std::string getUserId() const { return userId_; }
    void setUserId(const std::string& id) { userId_ = id; }

    std::string getAccessToken() const { return accessToken_; }
    void setAccessToken(const std::string& token) { accessToken_ = token; }

private:
    Config() = default;
    std::string serverUrl_;
    std::string userId_;
    std::string accessToken_;
};

} // namespace utils
} // namespace emby
