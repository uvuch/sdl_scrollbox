cmake_minimum_required(VERSION 3.16)

# 1. Try system SDL_TTF package first
find_package(SDL2_TTF QUIET)
if(SDL2_TTF_FOUND)
    message(STATUS "Using SDL_TTF via find_package")
endif()

# 2. Try using a vendored SDL_TTF library
if(NOT SDL2_TTF_FOUND AND EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL_TTF/CMakeLists.txt")
    add_subdirectory(find_package(SDL_ttf REQUIRED))
    message(STATUS "Using SDL_TTF via add_subdirectory")
    set(SDL2_TTF_FOUND TRUE)
endif()

# 3. Download SDL TTF, and use that.
if(NOT SDL2_TTF_FOUND)
    include(FetchContent)
    set(SDL_TTF_SHARED TRUE CACHE BOOL "Build a SDL TTF shared library (if available)")
    set(SDL_TTF_STATIC TRUE CACHE BOOL "Build a SDL TTF static library (if available)")
    FetchContent_Declare(
        SDL2_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
        GIT_TAG SDL2
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
    )
    message(STATUS "Using SDL_TTF via FetchContent")
    FetchContent_MakeAvailable(SDL2_ttf)
    set_property(DIRECTORY "${CMAKE_BINARY_DIR}/_deps/sdl2_ttf-src" PROPERTY EXCLUDE_FROM_ALL TRUE)
endif()
