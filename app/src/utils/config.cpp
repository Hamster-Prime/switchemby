#include "utils/config.hpp"
#include <fstream>

namespace emby {
namespace utils {

Config& Config::getInstance() {
    static Config instance;
    return instance;
}

bool Config::load(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    try {
        nlohmann::json j;
        file >> j;

        serverUrl_ = j.value("serverUrl", "");
        userId_ = j.value("userId", "");
        accessToken_ = j.value("accessToken", "");

        return true;
    } catch (...) {
        return false;
    }
}

bool Config::save(const std::string& path) {
    nlohmann::json j;
    j["serverUrl"] = serverUrl_;
    j["userId"] = userId_;
    j["accessToken"] = accessToken_;

    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }

    file << j.dump(4);
    return true;
}

} // namespace utils
} // namespace emby
