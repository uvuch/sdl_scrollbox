//
//  menu_item.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/18/23.
//

#include "menu_item.h"
#include "iostream"

MenuItem::MenuItem(std::string label, int x, int y, int w, int h) : m_strLabel(label)
{
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = w;
    m_rect.h = h;
    
    myFont = TTF_OpenFont("assets/fonts/Open 24 Display St.ttf", 30);
    if (myFont) {
        m_pSurface = TTF_RenderText_Solid(myFont, label.c_str(), white);
        TTF_CloseFont(myFont);
    }
}

bool MenuItem::handleEvents(const SDL_Event& event) {
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            return this->onMouseBtnDownHandler(event);
    }

    return false;
}

void MenuItem::update(int x, int y) {
    m_rect.x = x;
    m_rect.y = y;
}

void MenuItem::draw() {
    SDL_Renderer* pRenderer = Game::Instance()->getRenderer();
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255); // RGBA
    SDL_RenderFillRect(pRenderer, &m_rect);
    SDL_SetRenderDrawColor(pRenderer, 100, 0, 0, 255); // RGBA
    SDL_RenderDrawRect(pRenderer, &m_rect);
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, m_pSurface);
    SDL_Rect fontRect; //create a rect
    
    fontRect.w = m_pSurface->w ; // controls the width of the rect
    fontRect.h = m_pSurface->h;
    fontRect.x = m_rect.x + (m_rect.w - fontRect.w) / 2;  //controls the rect's x coordinate
    fontRect.y = m_rect.y; // controls the rect's y coordinte
    SDL_RenderCopy(pRenderer, texture, NULL, &fontRect);
    
    SDL_DestroyTexture(texture);
}

bool MenuItem::onMouseBtnDownHandler(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT &&
        event.button.x >= m_rect.x && event.button.x <= m_rect.x + m_rect.w &&
        event.button.y >= m_rect.y && event.button.y <= m_rect.y + m_rect.h)
    {
        std::cout << "Menu item \"" << this->getLabel() << "\" clicked  " << std::endl;
        return true;
    }

    return false;
}
