#pragma once

#include "api/http.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <functional>

namespace emby {

// Forward declarations
using json = nlohmann::json;
using OnError = std::function<void(const std::string&, int)>;

// Emby API configuration
struct ApiConfig {
    std::string serverUrl;
    std::string userId;
    std::string accessToken;
    std::string deviceId;
    std::string deviceName;
    std::string clientName = "SwitchEmby";
    std::string clientVersion = "1.0.0";
};

// Main Emby API class
class EmbyClient {
public:
    EmbyClient();
    ~EmbyClient();

    // Configuration
    void setConfig(const ApiConfig& config);
    ApiConfig getConfig() const { return config_; }

    // Generic JSON request methods
    template<typename Result>
    void getJSON(const std::function<void(Result)>& callback,
                 OnError error,
                 const std::string& endpoint);

    template<typename Result>
    void postJSON(const json& data,
                  const std::function<void(Result)>& callback,
                  OnError error,
                  const std::string& endpoint);

    // Build full URL
    std::string buildUrl(const std::string& endpoint) const;

    // Get authorization header value
    std::string getAuthHeader() const;

private:
    ApiConfig config_;
    http::HttpClient httpClient_;
};

} // namespace emby
