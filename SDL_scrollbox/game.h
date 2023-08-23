//
//  game.h
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#ifndef game_h
#define game_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <vector>
#include <iostream>
#include <string>

#include "object.h"
#include "error.h"
#include "menu.h"

class Game
{
public:
    static Game* Instance();
    static void finish();
    
    SDL_Renderer* getRenderer();
    bool init();
    bool running() { return !m_bQuit; }
    void handleEvents();
    void update();
    void render();
    
private:
    static Game *s_pInstance;
    bool m_bQuit;
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    std::vector<Object*> m_objects;
    
    Game();
    ~Game();
};


#endif /* game_h */
