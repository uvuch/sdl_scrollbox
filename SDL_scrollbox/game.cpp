//
//  game.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 7/9/23.
//
#include "game.h"

Game* Game::s_pInstance = nullptr;

Game* Game::Instance() {
    if (!s_pInstance) s_pInstance = new Game();
    
    return s_pInstance;
}

void Game::finish() {
    if (s_pInstance) delete s_pInstance;
}

SDL_Renderer* Game::getRenderer() {
    return m_pRenderer;
}

Game::Game() : m_bQuit(true) {};

Game::~Game() {
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
        std::cout << "Deleting objects..." << std::endl;
        delete m_objects[i];
    }
    m_objects.clear();

    if (m_pRenderer) SDL_DestroyRenderer(m_pRenderer);
    if (m_pWindow) SDL_DestroyWindow(m_pWindow);
    
    TTF_Quit();
    SDL_Quit();
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return errorMessage(SDL_GetError());
    
    m_pWindow = SDL_CreateWindow("Basic Game Engine", 0, 0, 1024, 768, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (m_pWindow) m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    if (!m_pWindow || !m_pRenderer)
        return errorMessage(SDL_GetError());
    
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
    SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 255, 255); // RGBA
    SDL_RenderClear(m_pRenderer);
    
    for(std::vector<Object*>::size_type i = 0; i != m_objects.size(); i++ ) {
        m_objects[i]->draw();
    }
    
    if (SDL_GetTicks() - started_at < 1000.0 / 60)
        SDL_Delay(1000.0 / 60 - (SDL_GetTicks() - started_at));
    
    SDL_RenderPresent(m_pRenderer);
}
