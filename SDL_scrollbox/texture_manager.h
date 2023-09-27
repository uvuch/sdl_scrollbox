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
    static TextureManager& Instance();

    SDL_Texture* get(std::string id);
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    bool load(SDL_Surface* pSurface, std::string id, SDL_Renderer* pRenderer);
    bool load(SDL_Texture* pTexture, std::string id);
    
private:
    TextureManager();
    ~TextureManager();

    std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif /* texture_manager_h */
