//
//  texture_manager.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/16/23.
//

#include "texture_manager.h"

#include <iostream>

TextureManager::TextureManager() {
    std::cout << "Texture Manager constructor called" << std::endl;
}

TextureManager::~TextureManager() {
    std::cout << "Texture Manager destructor called" << std::endl;

    for(const auto& el: m_textureMap) {
        SDL_DestroyTexture(el.second);
        std::cout << "Destroyed texture with ID '" << el.first << "'" << std::endl;
    }

    std::cout << "Cleaning texture map (current size=" << m_textureMap.size() << ")... ";
    m_textureMap.clear();
    if (m_textureMap.size())
        std::cout << "size > 0 after clean() call" << std::endl;
    else
        std::cout << "cleaned" << std::endl;
}

TextureManager& TextureManager::Instance() {
    static TextureManager instance;        
    return instance;
}

SDL_Texture* TextureManager::get(std::string id) {
    return m_textureMap[id];
}

bool TextureManager::load(SDL_Texture* pTexture, std::string id) {\
    if (!pTexture) return false;
    
    m_textureMap[id] = pTexture;
    return true;
}

bool TextureManager::load(SDL_Surface* pSurface, std::string id, SDL_Renderer* pRenderer) {
    if (!pSurface) return false;
    
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);    
    return load(pTexture, id);
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    bool isTextureLoaded = load(pTempSurface, id, pRenderer);

    if (pTempSurface) SDL_FreeSurface(pTempSurface);

    return isTextureLoaded;
}
