# Borealis UI library
# Add as git submodule: git submodule add https://github.com/natinusala/borealis.git library/borealis

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/borealis)
    add_subdirectory(borealis)
else()
    message(WARNING "Borealis not found. Please run: git submodule update --init --recursive")
endif()
