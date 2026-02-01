#pragma once

#include <string>
#include <vector>

namespace emby {
namespace utils {

class StringUtils {
public:
    static std::string trim(const std::string& str);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::string join(const std::vector<std::string>& parts, const std::string& delimiter);
    static std::string toLower(const std::string& str);
    static std::string toUpper(const std::string& str);
};

} // namespace utils
} // namespace emby
