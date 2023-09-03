//
//  renderer.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 9/2/23.
//

#include "renderer.h"

Renderer* Renderer::s_pRenderer = nullptr;

Renderer::Renderer(char* windowTitle, int x, int y, int w, int h, int flags) {
    m_pWindow = SDL_CreateWindow(windowTitle, x, y, w, h, flags);
    if (m_pWindow) m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
}

Renderer::~Renderer() {
    if (m_pRenderer) SDL_DestroyRenderer(m_pRenderer);
    if (m_pWindow) SDL_DestroyWindow(m_pWindow);
}

bool Renderer::init(char* windowTitle, int x, int y, int w, int h, int flags) {
    if (!s_pRenderer) s_pRenderer = new Renderer(windowTitle, x, y, w, h, flags);
    if (!s_pRenderer) return false;
    
    if (!s_pRenderer->m_pRenderer) return errorMessage(SDL_GetError());
    
    return true;
}

SDL_Renderer* Renderer::instance() {
    if (!s_pRenderer) return nullptr;
    
    return s_pRenderer->m_pRenderer;
}

void Renderer::free() {
    if (s_pRenderer) delete s_pRenderer;
}
