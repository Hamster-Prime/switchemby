#include "api/http.hpp"
#include <sstream>
#include <thread>

namespace emby {
namespace http {

HttpClient::HttpClient() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_ = curl_easy_init();
}

HttpClient::~HttpClient() {
    if (curl_) {
        curl_easy_cleanup(curl_);
    }
    curl_global_cleanup();
}

size_t HttpClient::writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* str = static_cast<std::string*>(userp);
    str->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

bool HttpClient::request(const RequestConfig& config, std::string& response, std::string& error) {
    if (!curl_) {
        error = "CURL not initialized";
        return false;
    }

    response.clear();

    // Set URL
    curl_easy_setopt(curl_, CURLOPT_URL, config.url.c_str());

    // Set method
    switch (config.method) {
        case Method::POST:
            curl_easy_setopt(curl_, CURLOPT_POST, 1L);
            curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, config.body.c_str());
            break;
        case Method::PUT:
            curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, config.body.c_str());
            break;
        case Method::DELETE:
            curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "DELETE");
            break;
        default:
            curl_easy_setopt(curl_, CURLOPT_HTTPGET, 1L);
            break;
    }

    // Set headers
    struct curl_slist* headers = nullptr;
    for (const auto& [key, value] : defaultHeaders_) {
        std::string header = key + ": " + value;
        headers = curl_slist_append(headers, header.c_str());
    }
    for (const auto& [key, value] : config.headers) {
        std::string header = key + ": " + value;
        headers = curl_slist_append(headers, header.c_str());
    }
    if (headers) {
        curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers);
    }

    // Set timeout
    curl_easy_setopt(curl_, CURLOPT_TIMEOUT_MS, config.timeout);

    // Set write callback
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response);

    // Perform request
    CURLcode res = curl_easy_perform(curl_);

    if (headers) {
        curl_slist_free_all(headers);
    }

    if (res != CURLE_OK) {
        error = curl_easy_strerror(res);
        return false;
    }

    long httpCode = 0;
    curl_easy_getinfo(curl_, CURLINFO_RESPONSE_CODE, &httpCode);

    if (httpCode >= 400) {
        error = "HTTP error: " + std::to_string(httpCode);
        return false;
    }

    return true;
}

void HttpClient::requestAsync(const RequestConfig& config, OnSuccess success, OnError errorCb) {
    std::thread([this, config, success, errorCb]() {
        std::string response, error;
        if (request(config, response, error)) {
            if (success) success(response);
        } else {
            if (errorCb) errorCb(error, 0);
        }
    }).detach();
}

bool HttpClient::get(const std::string& url, std::string& response, std::string& error) {
    RequestConfig config;
    config.url = url;
    config.method = Method::GET;
    return request(config, response, error);
}

bool HttpClient::post(const std::string& url, const std::string& body, std::string& response, std::string& error) {
    RequestConfig config;
    config.url = url;
    config.method = Method::POST;
    config.body = body;
    return request(config, response, error);
}

void HttpClient::setDefaultHeader(const std::string& key, const std::string& value) {
    defaultHeaders_[key] = value;
}

void HttpClient::clearDefaultHeaders() {
    defaultHeaders_.clear();
}

} // namespace http
} // namespace emby
