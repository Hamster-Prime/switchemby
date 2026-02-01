# Borealis UI library
# Add as git submodule: git submodule add https://github.com/natinusala/borealis.git library/borealis

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/borealis)
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

    # Set include directories
    target_include_directories(borealis PUBLIC
        borealis/library/include
        borealis/library/lib/extern/fmt/include
        borealis/library/lib/extern/yoga/src
        borealis/library/lib/extern/nanovg-deko3d/include
        borealis/library/lib/extern/tweeny/include
        borealis/library/include/borealis/extern
        borealis/library/include/borealis/extern/tinyxml2
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
