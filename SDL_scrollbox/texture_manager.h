//
//  texture_manager.h
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/16/23.
//

#ifndef texture_manager_h
#define texture_manager_h

#include <map>
#include <string>
#include <SDL2/SDL.h>

#if defined(__APPLE__) || defined(__MACH__)
    #include <SDL2_image/SDL_image.h>
#else
    #include <SDL2/SDL_image.h>
#endif

class TextureManager {
public:
    static TextureManager* Instance();
    
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    SDL_Texture* get(std::string id);

    //void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    //void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
private:
    static TextureManager* s_pInstance;

    TextureManager() {};
    
    std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif /* texture_manager_h */
