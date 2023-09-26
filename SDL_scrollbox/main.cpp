//
//  main.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#include <cassert>
#include "error.h"
#include "game.h"

int main(int argc, const char * argv[]) {
    int returnResult = -1;
    Game *pGame = new Game();
    assert(pGame);

    if (!pGame->init()) {
        errorMessage("Could not create Game object");
        return -1;
    }
    
    while(pGame->running()) {
        pGame->handleEvents();
        pGame->update();
        pGame->render();
    }

    delete pGame;
    return 0;
}
