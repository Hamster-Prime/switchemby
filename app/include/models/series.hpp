#pragma once

#include "models/media_item.hpp"
#include <vector>
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct Series : public MediaItem {
    int productionYear;
    std::vector<std::string> genres;
    std::string status;
    int seasonCount;
    int episodeCount;

    static Series fromJson(const nlohmann::json& j) {
        Series series;
        series.id = j.value("Id", "");
        series.name = j.value("Name", "");
        series.type = j.value("Type", "");
        series.overview = j.value("Overview", "");
        series.runTimeTicks = j.value("RunTimeTicks", 0L);
        series.productionYear = j.value("ProductionYear", 0);
        series.status = j.value("Status", "");

        if (j.contains("Genres") && j["Genres"].is_array()) {
            for (const auto& genre : j["Genres"]) {
                series.genres.push_back(genre.get<std::string>());
            }
        }

        series.seasonCount = j.value("ChildCount", 0);
        series.episodeCount = j.value("RecursiveItemCount", 0);

        return series;
    }
};

} // namespace models
} // namespace emby
