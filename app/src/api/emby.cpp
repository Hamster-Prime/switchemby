#include "api/emby.hpp"
#include "utils/logger.hpp"
#include <sstream>

namespace emby {

EmbyClient::EmbyClient() {
    utils::Logger::getInstance().info("EmbyClient initialized");
}

EmbyClient::~EmbyClient() {
}

void EmbyClient::setConfig(const ApiConfig& config) {
    config_ = config;

    utils::Logger::getInstance().info("Emby server configured: " + config_.serverUrl);
    utils::Logger::getInstance().debug("Client: " + config_.clientName + " v" + config_.clientVersion);

    // Set default headers
    httpClient_.setDefaultHeader("Content-Type", "application/json");
    httpClient_.setDefaultHeader("Accept", "application/json");

    // Set Emby authorization header
    if (!config_.accessToken.empty()) {
        httpClient_.setDefaultHeader("X-Emby-Authorization", getAuthHeader());
        utils::Logger::getInstance().debug("Access token configured");
    }
}

std::string EmbyClient::buildUrl(const std::string& endpoint) const {
    std::string url = config_.serverUrl;
    if (url.back() == '/') {
        url.pop_back();
    }
    if (endpoint.front() != '/') {
        url += '/';
    }
    url += endpoint;
    return url;
}

std::string EmbyClient::getAuthHeader() const {
    std::ostringstream oss;
    oss << "MediaBrowser "
        << "Client=\"" << config_.clientName << "\", "
        << "Device=\"" << config_.deviceName << "\", "
        << "DeviceId=\"" << config_.deviceId << "\", "
        << "Version=\"" << config_.clientVersion << "\"";

    if (!config_.accessToken.empty()) {
        oss << ", Token=\"" << config_.accessToken << "\"";
    }

    return oss.str();
}

} // namespace emby
