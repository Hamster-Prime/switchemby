cmake_minimum_required(VERSION 3.13)

project(switchemby_app)

# Source files
set(APP_SOURCES
    src/main.cpp

    # API layer
    src/api/http.cpp
    src/api/emby.cpp
    src/api/emby/auth.cpp
    src/api/emby/library.cpp
    src/api/emby/playback.cpp
    src/api/emby/transcode.cpp

    # Models
    src/models/server.cpp
    src/models/user.cpp
    src/models/media_item.cpp

    # Player
    src/player/mpv_core.cpp
    src/player/video_player.cpp
    src/player/subtitle_manager.cpp
    src/player/playback_state.cpp

    # Views
    src/view/media_grid.cpp
    src/view/media_card.cpp
    src/view/detail_view.cpp
    src/view/player_controls.cpp

    # Tabs
    src/tab/home_tab.cpp
    src/tab/library_tab.cpp
    src/tab/search_tab.cpp
    src/tab/settings_tab.cpp

    # Activities
    src/activity/main_activity.cpp
    src/activity/server_list.cpp
    src/activity/login_activity.cpp
    src/activity/player_activity.cpp

    # Utils
    src/utils/config.cpp
    src/utils/cache.cpp
    src/utils/image_loader.cpp
    src/utils/string_utils.cpp
    src/utils/time_utils.cpp
)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../library/borealis/library/include
)

if(PLATFORM_SWITCH)
    # Switch build
    add_executable(${PROJECT_NAME}.elf ${APP_SOURCES})

    target_include_directories(${PROJECT_NAME}.elf PRIVATE
        ${DEVKITPRO}/portlibs/switch/include
    )

    target_link_libraries(${PROJECT_NAME}.elf
        borealis
        mpv
        curl
        EGL
        glapi
        drm_nouveau
        nx
    )

    # Generate NRO
    add_custom_target(${PROJECT_NAME}.nro ALL
        COMMAND ${DEVKITPRO}/tools/bin/elf2nro ${PROJECT_NAME}.elf ${PROJECT_NAME}.nro
        DEPENDS ${PROJECT_NAME}.elf
    )

elseif(PLATFORM_DESKTOP)
    # Desktop build
    add_executable(${PROJECT_NAME} ${APP_SOURCES})

    target_include_directories(${PROJECT_NAME} PRIVATE
        ${MPV_INCLUDE_DIRS}
        ${CURL_INCLUDE_DIRS}
    )

    target_link_libraries(${PROJECT_NAME}
        borealis
        ${MPV_LIBRARIES}
        ${CURL_LIBRARIES}
    )
endif()
