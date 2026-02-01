#pragma once

#include "models/media_item.hpp"
#include <nlohmann/json.hpp>

namespace emby {
namespace models {

struct Episode : public MediaItem {
    std::string seriesId;
    std::string seriesName;
    int seasonNumber;
    int episodeNumber;
    std::string premiereDate;

    static Episode fromJson(const nlohmann::json& j) {
        Episode episode;
        episode.id = j.value("Id", "");
        episode.name = j.value("Name", "");
        episode.type = j.value("Type", "");
        episode.overview = j.value("Overview", "");
        episode.runTimeTicks = j.value("RunTimeTicks", 0L);
        episode.seriesId = j.value("SeriesId", "");
        episode.seriesName = j.value("SeriesName", "");
        episode.seasonNumber = j.value("ParentIndexNumber", 0);
        episode.episodeNumber = j.value("IndexNumber", 0);
        episode.premiereDate = j.value("PremiereDate", "");
        return episode;
    }
};

} // namespace models
} // namespace emby
