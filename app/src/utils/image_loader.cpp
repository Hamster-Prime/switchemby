#include "utils/image_loader.hpp"
#include <thread>

namespace emby {
namespace utils {

ImageLoader& ImageLoader::getInstance() {
    static ImageLoader instance;
    return instance;
}

void ImageLoader::loadAsync(const std::string& url, ImageCallback callback) {
    std::thread([url, callback]() {
        // TODO: Implement actual image download
        if (callback) {
            callback(url);
        }
    }).detach();
}

std::string ImageLoader::getCachePath(const std::string& url) const {
    // TODO: Implement cache path generation
    return url;
}

} // namespace utils
} // namespace emby
