#pragma once

#include "models/media_item.hpp"
#include <vector>
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct Movie : public MediaItem {
    int productionYear;
    std::vector<std::string> genres;
    std::string communityRating;
    std::string officialRating;
    std::vector<std::string> studios;

    static Movie fromJson(const nlohmann::json& j) {
        Movie movie;
        movie.id = j.value("Id", "");
        movie.name = j.value("Name", "");
        movie.type = j.value("Type", "");
        movie.overview = j.value("Overview", "");
        movie.runTimeTicks = j.value("RunTimeTicks", 0L);
        movie.productionYear = j.value("ProductionYear", 0);

        if (j.contains("Genres") && j["Genres"].is_array()) {
            for (const auto& genre : j["Genres"]) {
                movie.genres.push_back(genre.get<std::string>());
            }
        }

        movie.communityRating = j.value("CommunityRating", "");
        movie.officialRating = j.value("OfficialRating", "");

        if (j.contains("Studios") && j["Studios"].is_array()) {
            for (const auto& studio : j["Studios"]) {
                if (studio.contains("Name")) {
                    movie.studios.push_back(studio["Name"].get<std::string>());
                }
            }
        }

        return movie;
    }
};

} // namespace models
} // namespace emby
