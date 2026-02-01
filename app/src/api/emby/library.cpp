#include "api/emby/library.hpp"
#include <sstream>

namespace emby {
namespace library {

std::string ItemQuery::toQueryString() const {
    std::ostringstream oss;
    oss << "?StartIndex=" << startIndex
        << "&Limit=" << limit
        << "&Recursive=" << (recursive ? "true" : "false")
        << "&SortBy=" << sortBy
        << "&SortOrder=" << sortOrder;

    if (!parentId.empty()) {
        oss << "&ParentId=" << parentId;
    }
    if (!includeItemTypes.empty()) {
        oss << "&IncludeItemTypes=" << includeItemTypes;
    }

    return oss.str();
}

LibraryView LibraryView::fromJson(const json& j) {
    LibraryView view;
    view.id = j.value("Id", "");
    view.name = j.value("Name", "");
    view.collectionType = j.value("CollectionType", "");
    return view;
}

} // namespace library
} // namespace emby
