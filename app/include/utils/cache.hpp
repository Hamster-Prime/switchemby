#pragma once

#include <string>
#include <map>

namespace emby {
namespace utils {

class Cache {
public:
    static Cache& getInstance();

    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    bool has(const std::string& key) const;
    void remove(const std::string& key);
    void clear();

private:
    Cache() = default;
    std::map<std::string, std::string> cache_;
};

} // namespace utils
} // namespace emby
