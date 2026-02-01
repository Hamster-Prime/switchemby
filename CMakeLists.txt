cmake_minimum_required(VERSION 3.13)

project(switchemby)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform detection
option(PLATFORM_SWITCH "Build for Nintendo Switch" OFF)
option(PLATFORM_DESKTOP "Build for Desktop (Windows/Linux/macOS)" ON)

# Ensure platforms are mutually exclusive
if(PLATFORM_SWITCH)
    set(PLATFORM_DESKTOP OFF CACHE BOOL "Build for Desktop" FORCE)
endif()

# Global compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Switch-specific configuration
if(PLATFORM_SWITCH)
    if(NOT DEFINED ENV{DEVKITPRO})
        message(FATAL_ERROR "Please set DEVKITPRO in your environment")
    endif()

    set(DEVKITPRO $ENV{DEVKITPRO})
    set(CMAKE_TOOLCHAIN_FILE "${DEVKITPRO}/cmake/Switch.cmake")

    set(CMAKE_C_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-gcc")
    set(CMAKE_CXX_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-g++")

    add_compile_definitions(
        __SWITCH__
        BOREALIS_USE_OPENGL
    )
endif()

# Desktop-specific configuration
if(PLATFORM_DESKTOP AND NOT PLATFORM_SWITCH)
    add_compile_definitions(
        PLATFORM_DESKTOP
    )

    # Find required packages
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(MPV REQUIRED mpv)
    pkg_check_modules(CURL REQUIRED libcurl)
endif()

# Add subdirectories
add_subdirectory(library)
add_subdirectory(app)
