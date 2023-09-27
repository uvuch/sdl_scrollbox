#include "font_manager.h"
#include <iostream>

FontManager& FontManager::Instance() {
    static FontManager instance;
    return instance;
}

FontManager::FontManager() {
    std::cout << "Font Manager constructor called" << std::endl;
}

FontManager::~FontManager() {
    std::cout << "Font Manager destructor called" << std::endl;
}