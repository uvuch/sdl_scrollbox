//
//  main.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#include "error.h"
#include "game.h"

int main(int argc, const char * argv[]) {
    int returnResult = -1;
    Game *pGame = Game::Instance();

    if (pGame && pGame->init()) {
        while(pGame->running()) {
            pGame->handleEvents();
            pGame->update();
            pGame->render();
        }

        returnResult = 0;;
    }
    
    Game::finish();
    return returnResult;
}
