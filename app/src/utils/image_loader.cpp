#include "utils/image_loader.hpp"
#include "api/http.hpp"
#include "utils/logger.hpp"
#include <thread>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <functional>

namespace emby {
namespace utils {

ImageLoader& ImageLoader::getInstance() {
    static ImageLoader instance;
    return instance;
}

void ImageLoader::loadAsync(const std::string& url, ImageCallback callback) {
    std::thread([this, url, callback]() {
        std::string cachePath = getCachePath(url);

        // Check if cached file exists
        std::ifstream cacheFile(cachePath);
        if (cacheFile.good()) {
            Logger::getInstance().debug("Image loaded from cache: " + cachePath);
            if (callback) callback(cachePath);
            return;
        }

        // Download image
        http::HttpClient client;
        http::RequestConfig config;
        config.url = url;
        config.method = http::Method::GET;

        std::string response, error;
        if (client.request(config, response, error)) {
            // Save to cache
            std::ofstream outFile(cachePath, std::ios::binary);
            if (outFile.is_open()) {
                outFile.write(response.c_str(), response.size());
                outFile.close();
                Logger::getInstance().debug("Image downloaded and cached: " + cachePath);
                if (callback) callback(cachePath);
            } else {
                Logger::getInstance().error("Failed to save image cache: " + cachePath);
            }
        } else {
            Logger::getInstance().error("Failed to download image: " + error);
        }
    }).detach();
}

std::string ImageLoader::getCachePath(const std::string& url) const {
    // Generate hash from URL
    std::hash<std::string> hasher;
    size_t hash = hasher(url);

    std::ostringstream oss;
    oss << "/switch/switchemby/cache/img_" << std::hex << hash << ".jpg";
    return oss.str();
}

} // namespace utils
} // namespace emby
