#pragma once

#include <string>
#include <functional>
#include <map>
#include <memory>
#include <curl/curl.h>

namespace emby {
namespace http {

// Callback types
using OnSuccess = std::function<void(const std::string& response)>;
using OnError = std::function<void(const std::string& error, int code)>;

// HTTP methods
enum class Method {
    GET,
    POST,
    PUT,
    DELETE
};

// HTTP request configuration
struct RequestConfig {
    std::string url;
    Method method = Method::GET;
    std::map<std::string, std::string> headers;
    std::string body;
    int timeout = 30000; // milliseconds
    int retries = 3;
};

// HTTP client class
class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    // Synchronous requests
    bool request(const RequestConfig& config, std::string& response, std::string& error);

    // Async requests
    void requestAsync(const RequestConfig& config, OnSuccess success, OnError error);

    // Convenience methods
    bool get(const std::string& url, std::string& response, std::string& error);
    bool post(const std::string& url, const std::string& body, std::string& response, std::string& error);

    // Set default headers
    void setDefaultHeader(const std::string& key, const std::string& value);
    void clearDefaultHeaders();

private:
    CURL* curl_;
    std::map<std::string, std::string> defaultHeaders_;

    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

} // namespace http
} // namespace emby
