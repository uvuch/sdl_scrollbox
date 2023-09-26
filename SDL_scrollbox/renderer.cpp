//
//  renderer.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 9/2/23.
//

#include "renderer.h"
#include <cassert>

Renderer* Renderer::s_pRenderer = nullptr;

SDL_Renderer* Renderer::instance() {    
    return s_pRenderer->m_pRenderer;
}

bool Renderer::init(const std::string windowTitle, int x, int y, int w, int h, int flags) {
    if (!s_pRenderer) s_pRenderer = new Renderer(windowTitle, x, y, w, h, flags);
    assert(s_pRenderer);
    
    if (!s_pRenderer->m_pRenderer) return errorMessage(SDL_GetError());
    
    return true;
}

void Renderer::quit() {
    if (s_pRenderer) delete s_pRenderer;
}

Renderer::Renderer(const std::string windowTitle, int x, int y, int w, int h, int flags) {
    m_pWindow = SDL_CreateWindow(windowTitle.c_str(), x, y, w, h, flags);
    if (m_pWindow) m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
}

Renderer::~Renderer() {
    if (m_pRenderer) SDL_DestroyRenderer(m_pRenderer);
    if (m_pWindow) SDL_DestroyWindow(m_pWindow);
}
