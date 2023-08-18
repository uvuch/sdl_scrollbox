//
//  game.h
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#ifndef game_h
#define game_h

#include <SDL2/SDL.h>
#include <vector>
#include "object.h"

class Game
{
public:
    Game();
    ~Game();

    int init();
    bool running() { return !m_bQuit; }
    void handleEvents();
    void update();
    void render();
    
private:
    bool m_bQuit;
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    std::vector<Object*> m_objects;
};


#endif /* game_h */
