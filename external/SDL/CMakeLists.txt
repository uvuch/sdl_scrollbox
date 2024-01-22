cmake_minimum_required(VERSION 3.16)

# 1. Try system SDL2 package first
find_package(SDL2 QUIET)
if(SDL2_FOUND)
    message(STATUS "Using SDL2 via find_package")
endif()

# 2. Try using a vendored SDL library
if(NOT SDL2_FOUND AND EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL/CMakeLists.txt")
    add_subdirectory(SDL)
    message(STATUS "Using SDL2 via add_subdirectory")
    set(SDL2_FOUND TRUE)
endif()

# 3. Download SDL, and use that.
if(NOT SDL2_FOUND)
    include(FetchContent)
    set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
    set(SDL_STATIC TRUE CACHE BOOL "Build a SDL static library (if available)")
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.28.5
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
    )
    message(STATUS "Using SDL2 via FetchContent")
    FetchContent_MakeAvailable(SDL2)
    set_property(DIRECTORY "${CMAKE_BINARY_DIR}/_deps/sdl2-src" PROPERTY EXCLUDE_FROM_ALL TRUE)
endif()
