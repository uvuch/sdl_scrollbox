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

TTF_Font* FontManager::get(std::string id) {
    return m_fontMap[id];
}

bool FontManager::load(std::string fontFileName, std::string id, int size) {
    TTF_Font* pFont = TTF_OpenFont(fontFileName.c_str(), size);
    if (!pFont) return false;
    
    m_fontMap[id] = pFont;
    return true;
}