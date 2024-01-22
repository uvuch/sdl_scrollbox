cmake_minimum_required(VERSION 3.16)

# 1. Try system SDL_Image package first
find_package(SDL2_Image QUIET)
if(SDL2_Image_FOUND)
    message(STATUS "Using SDL_Image via find_package")
endif()

# 2. Try using a vendored SDL_Image library
if(NOT SDL2_Image_FOUND AND EXISTS "${CMAKE_CURRENT_LIST_DIR}/SDL_Image/CMakeLists.txt")
    add_subdirectory(SDL_Image)
    message(STATUS "Using SDL_Image via add_subdirectory")
    set(SDL2_Image_FOUND TRUE)
endif()

# 3. Download SDL, and use that.
if(NOT SDL2_Image_FOUND)
    include(FetchContent)
    set(SDL_Image_SHARED TRUE CACHE BOOL "Build a SDL Image shared library (if available)")
    set(SDL_Image_STATIC TRUE CACHE BOOL "Build a SDL Image static library (if available)")
    FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG SDL2
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
    )
    message(STATUS "Using SDL_Image via FetchContent")
    FetchContent_MakeAvailable(SDL2_image)
    set_property(DIRECTORY "${CMAKE_BINARY_DIR}/_deps/sdl2_image-src" PROPERTY EXCLUDE_FROM_ALL TRUE)
endif()
