# Borealis UI library
# Add as git submodule: git submodule add https://github.com/natinusala/borealis.git library/borealis

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/borealis)
    # Patch dk_renderer.hpp to include <optional> header
    set(DK_RENDERER_FILE "${CMAKE_CURRENT_SOURCE_DIR}/borealis/library/lib/extern/nanovg-deko3d/include/nanovg/dk_renderer.hpp")
    if(EXISTS ${DK_RENDERER_FILE})
        file(READ ${DK_RENDERER_FILE} DK_RENDERER_CONTENT)
        string(FIND "${DK_RENDERER_CONTENT}" "#include <optional>" OPTIONAL_FOUND)
        if(OPTIONAL_FOUND EQUAL -1)
            string(REPLACE "#include \"nanovg.h\"" "#include <optional>\n#include \"nanovg.h\"" DK_RENDERER_CONTENT "${DK_RENDERER_CONTENT}")
            file(WRITE ${DK_RENDERER_FILE} "${DK_RENDERER_CONTENT}")
            message(STATUS "Patched dk_renderer.hpp to include <optional>")
        endif()
    endif()

    # Patch swkbd.cpp to use correct API function
    set(SWKBD_FILE "${CMAKE_CURRENT_SOURCE_DIR}/borealis/library/lib/platforms/switch/swkbd.cpp")
    if(EXISTS ${SWKBD_FILE})
        file(READ ${SWKBD_FILE} SWKBD_CONTENT)
        string(FIND "${SWKBD_CONTENT}" "swkbdConfigSetStringLenMaxExt" SWKBD_EXT_FOUND)
        if(NOT SWKBD_EXT_FOUND EQUAL -1)
            string(REPLACE "swkbdConfigSetStringLenMaxExt" "swkbdConfigSetStringLenMax" SWKBD_CONTENT "${SWKBD_CONTENT}")
            file(WRITE ${SWKBD_FILE} "${SWKBD_CONTENT}")
            message(STATUS "Patched swkbd.cpp to use swkbdConfigSetStringLenMax")
        endif()
    endif()
    # Collect all borealis source files
    file(GLOB_RECURSE BOREALIS_SOURCES
        borealis/library/lib/core/*.cpp
        borealis/library/lib/views/*.cpp
        borealis/library/lib/platforms/switch/*.cpp
        borealis/library/lib/extern/glad/*.c
        borealis/library/lib/extern/nanovg-deko3d/source/*.c
        borealis/library/lib/extern/nanovg-deko3d/source/*.cpp
        borealis/library/lib/extern/nanovg-deko3d/source/framework/*.c
        borealis/library/lib/extern/nanovg-deko3d/source/framework/*.cpp
        borealis/library/lib/extern/nanovg-deko3d/shaders/*.c
        borealis/library/lib/extern/libretro-common/compat/*.c
        borealis/library/lib/extern/libretro-common/encodings/*.c
        borealis/library/lib/extern/libretro-common/features/*.c
        borealis/library/lib/extern/nxfmtwrapper/*.cpp
        borealis/library/lib/extern/yoga/src/yoga/event/*.cpp
        borealis/library/lib/extern/yoga/src/yoga/*.cpp
        borealis/library/lib/extern/tinyxml2/*.cpp
    )

    # Create borealis library
    add_library(borealis STATIC ${BOREALIS_SOURCES})

    # Set C++17 standard for borealis
    target_compile_features(borealis PUBLIC cxx_std_17)
    set_target_properties(borealis PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )

    # Set include directories
    target_include_directories(borealis PUBLIC
        borealis/library/include
        borealis/library/lib/extern/fmt/include
        borealis/library/lib/extern/yoga/src
        borealis/library/lib/extern/nanovg-deko3d/include
        borealis/library/lib/extern/tweeny/include
        borealis/library/include/borealis/extern
        borealis/library/include/borealis/extern/tinyxml2
        borealis/library/lib/extern/switch-libpulsar/include
        $ENV{DEVKITPRO}/portlibs/switch/include
    )

    # Set compile definitions
    target_compile_definitions(borealis PUBLIC
        YG_ENABLE_EVENTS
        BRLS_RESOURCES="romfs:/"
    )

    # Set compile options
    target_compile_options(borealis PRIVATE
        -fdata-sections
    )

    # Link libraries
    target_link_libraries(borealis PUBLIC
        deko3d
        m
    )
else()
    message(WARNING "Borealis not found. Please run: git submodule update --init --recursive")
endif()
