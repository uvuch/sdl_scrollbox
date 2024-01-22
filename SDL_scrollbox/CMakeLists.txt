cmake_minimum_required(VERSION 3.16)

add_executable(sdl_scrollbox main.cpp error.cpp game.cpp menu.cpp texture_manager.cpp)
add_dependencies(sdl_scrollbox SDL2::SDL2 SDL2_image SDL2_ttf)

target_link_libraries(sdl_scrollbox PRIVATE SDL2::SDL2 SDL2_image SDL2_ttf)