//
//  texture_manager.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/16/23.
//

#include "texture_manager.h"

TextureManager* TextureManager::s_pInstance = nullptr;

TextureManager* TextureManager::Instance() {
    if (!s_pInstance)
        s_pInstance = new TextureManager();
        
    return s_pInstance;
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if (!pTempSurface) return false;
    
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    if (!pTexture) return false;
    
    m_textureMap[id] = pTexture;
    return true;
}

SDL_Texture* TextureManager::get(std::string id) {
    return m_textureMap[id];
}

/*
void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    
    //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = srcRect.w = width;
    dstRect.h = srcRect.h = height;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}
*/
