//
//  game.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//
#include "game.h"

Game::Game() : m_bQuit(true) {};

Game::~Game() {   
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
        std::cout << "Deleting objects..." << std::endl;
        delete m_objects[i];
    }
    m_objects.clear();

    Renderer::quit();
    TTF_Quit();
    SDL_Quit();
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return errorMessage(SDL_GetError());
    
    if (!Renderer::init("Basic Menu Example", 0, 0, 3840, 2160, SDL_WINDOW_SHOWN))
        return false;
    
    TTF_Init();
    
    Menu* pMenu = new Menu();
    m_objects.push_back(pMenu);
    
    m_bQuit = false;
    
    return true;
}

void Game::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ )
            if (m_objects[i]->handleEvents(event))
                break;
        
        if (event.type == SDL_QUIT) {
            m_bQuit = true;
            std::cout << "SQL QUIT command issued" << std::endl;
        }
    }
}

void Game::update() {
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
            m_objects[i]->update();
    }
}

void Game::render() {
    int started_at = SDL_GetTicks();
    SDL_SetRenderDrawColor(Renderer::instance(), 25, 50, 106, 255); // RGBA
    SDL_RenderClear(Renderer::instance());
    
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
        m_objects[i]->draw();
    }
    
    if (SDL_GetTicks() - started_at < 1000.0 / 60)
        SDL_Delay(1000.0 / 60 - (SDL_GetTicks() - started_at));
    
    SDL_RenderPresent(Renderer::instance());
}
