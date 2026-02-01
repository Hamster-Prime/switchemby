#include "utils/cache.hpp"

namespace emby {
namespace utils {

Cache& Cache::getInstance() {
    static Cache instance;
    return instance;
}

void Cache::set(const std::string& key, const std::string& value) {
    cache_[key] = value;
}

std::string Cache::get(const std::string& key) const {
    auto it = cache_.find(key);
    return (it != cache_.end()) ? it->second : "";
}

bool Cache::has(const std::string& key) const {
    return cache_.find(key) != cache_.end();
}

void Cache::remove(const std::string& key) {
    cache_.erase(key);
}

void Cache::clear() {
    cache_.clear();
}

} // namespace utils
} // namespace emby
