//
//  main.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#include "error.h"
#include "game.h"

int main(int argc, const char * argv[]) {
    Game *pGame = new Game();
    if (!pGame)
        return errorMessage("Could not create game object");
    
    if (pGame->init() != 0) {
        delete pGame;
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
