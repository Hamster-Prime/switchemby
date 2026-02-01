#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace emby {
namespace library {

using json = nlohmann::json;

// Query parameters for library items
struct ItemQuery {
    std::string userId;
    std::string parentId;
    std::string includeItemTypes;
    std::string sortBy = "SortName";
    std::string sortOrder = "Ascending";
    int startIndex = 0;
    int limit = 100;
    bool recursive = true;

    std::string toQueryString() const;
};

// Library view
struct LibraryView {
    std::string id;
    std::string name;
    std::string collectionType;

    static LibraryView fromJson(const json& j);
};

} // namespace library
} // namespace emby
