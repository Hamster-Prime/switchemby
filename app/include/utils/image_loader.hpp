#pragma once

#include <string>
#include <functional>

namespace emby {
namespace utils {

using ImageCallback = std::function<void(const std::string& path)>;

class ImageLoader {
public:
    static ImageLoader& getInstance();

    void loadAsync(const std::string& url, ImageCallback callback);
    std::string getCachePath(const std::string& url) const;

private:
    ImageLoader() = default;
};

} // namespace utils
} // namespace emby
