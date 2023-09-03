//
//  game.h
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#ifndef game_h
#define game_h

#include "common.h"
#include "object.h"
#include "menu.h"

class Game
{
public:
    Game();
    ~Game();
    
    bool init();
    bool running() { return !m_bQuit; }
    void handleEvents();
    void update();
    void render();
    
private:
    bool m_bQuit;
    
    std::vector<Object*> m_objects;
};


#endif /* game_h */
