#pragma once

#include "api/http.hpp"
#include "utils/logger.hpp"
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

// Template method implementations
template<typename Result>
void EmbyClient::getJSON(const std::function<void(Result)>& callback,
                         OnError errorCallback,
                         const std::string& endpoint) {
    std::string url = buildUrl(endpoint);

    http::RequestConfig config;
    config.url = url;
    config.method = http::Method::GET;

    httpClient_.requestAsync(config,
        [callback, errorCallback, url](const std::string& response) {
            try {
                json j = json::parse(response);
                Result result = Result::fromJson(j);
                if (callback) callback(result);
            } catch (const json::parse_error& e) {
                utils::Logger::getInstance().error("JSON parse error for " + url + ": " + e.what());
                if (errorCallback) errorCallback("JSON parse error: " + std::string(e.what()), -1);
            } catch (const std::exception& e) {
                utils::Logger::getInstance().error("Error processing response for " + url + ": " + e.what());
                if (errorCallback) errorCallback("Error: " + std::string(e.what()), -1);
            }
        },
        errorCallback
    );
}

template<typename Result>
void EmbyClient::postJSON(const json& data,
                          const std::function<void(Result)>& callback,
                          OnError errorCallback,
                          const std::string& endpoint) {
    std::string url = buildUrl(endpoint);

    http::RequestConfig config;
    config.url = url;
    config.method = http::Method::POST;
    config.body = data.dump();

    httpClient_.requestAsync(config,
        [callback, errorCallback, url](const std::string& response) {
            try {
                json j = json::parse(response);
                Result result = Result::fromJson(j);
                if (callback) callback(result);
            } catch (const json::parse_error& e) {
                utils::Logger::getInstance().error("JSON parse error for " + url + ": " + e.what());
                if (errorCallback) errorCallback("JSON parse error: " + std::string(e.what()), -1);
            } catch (const std::exception& e) {
                utils::Logger::getInstance().error("Error processing response for " + url + ": " + e.what());
                if (errorCallback) errorCallback("Error: " + std::string(e.what()), -1);
            }
        },
        errorCallback
    );
}

} // namespace emby
