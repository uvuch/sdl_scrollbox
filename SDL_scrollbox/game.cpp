//
//  game.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//

#include "error.h"
#include "game.h"

Game::Game() : m_bQuit(true) {};

Game::~Game() {
     if (m_pRenderer) SDL_DestroyRenderer(m_pRenderer);
     if (m_pWindow) SDL_DestroyWindow(m_pWindow);

    SDL_Quit();
}

int Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return errorMessage(SDL_GetError());
    
     m_pWindow = SDL_CreateWindow("Basic Game Engine", 0, 0, 1024, 768, SDL_WINDOW_FULLSCREEN_DESKTOP);
     if (m_pWindow) m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
     if (!m_pWindow || !m_pRenderer)
         return errorMessage(SDL_GetError());
     
     SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 255, 255); // RGBA
    
    m_bQuit = false;
    
    return 0;
}

void Game::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ )
            if (m_objects[i]->handleEvents(event))
                break;
        
        if (event.type == SDL_QUIT)
            m_bQuit = true;
    }
}

void Game::update() {
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
            m_objects[i]->update();
    }
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);
    
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
            m_objects[i]->draw();
    }
    
    SDL_RenderPresent(m_pRenderer);
}
