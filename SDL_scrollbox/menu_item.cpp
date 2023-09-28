//
//  menu_item.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/18/23.
//

#include "menu_item.h"

int MenuItem::s_offsetX = 0;
int MenuItem::s_offsetY = 0;

MenuItem::MenuItem(std::string label) : m_strLabel(label), m_positionInFrame(-1) {
    m_rect.w = ITEM_WIDTH;
    m_rect.h = ITEM_HEIGHT;

    if (!FontManager::Instance().get("menuItemLabel"))
        //FontManager::Instance().load("assets/fonts/Open 24 Display St.ttf", "menuItemLabel", 60);
        //FontManager::Instance().load("assets/fonts/space age.ttf", "menuItemLabel", 60);
        FontManager::Instance().load("assets/fonts/Starcraft.otf", "menuItemLabel", 60);

    TTF_Font *pFont = FontManager::Instance().get("menuItemLabel");
    if (pFont) {
        SDL_Surface *pSurface = TTF_RenderText_Solid(pFont, label.c_str(), { 0xFF, 0xFF, 0xFF, 0 });
        if (pSurface)
            m_pTexture = SDL_CreateTextureFromSurface(Renderer::instance(), pSurface);
    }
    
}

MenuItem::~MenuItem() {
    if (m_pTexture) SDL_DestroyTexture(m_pTexture);
}

bool MenuItem::handleEvents(const SDL_Event& event) {
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            return this->onMouseBtnDownHandler(event);
    }

    return false;
}

void MenuItem::update() {
    m_rect.x = s_offsetX;
    m_rect.y = s_offsetY + m_positionInFrame * ITEM_HEIGHT;
}

void MenuItem::draw() {
    SDL_Renderer* pRenderer = Renderer::instance();
    
    // SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255); // RGBA
    // SDL_RenderFillRect(pRenderer, &m_rect);
    // SDL_SetRenderDrawColor(pRenderer, 100, 0, 0, 255); // RGBA
    // SDL_RenderDrawRect(pRenderer, &m_rect);
    
    // SDL_Rect fontRect;
    // fontRect.w = ITEM_WIDTH ; // controls the width of the rect
    // fontRect.h = ITEM_HEIGHT;
    // fontRect.x = m_rect.x + (m_rect.w - fontRect.w) / 2;  //controls the rect's x coordinate
    // fontRect.y = m_rect.y; // controls the rect's y coordinte
    SDL_RenderCopy(pRenderer, m_pTexture, NULL, &m_rect);
}

bool MenuItem::onMouseBtnDownHandler(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT &&
        event.button.x >= m_rect.x && event.button.x <= m_rect.x + m_rect.w &&
        event.button.y >= m_rect.y && event.button.y <= m_rect.y + m_rect.h)
    {
        std::cout << "Menu item \"" << this->getLabel() << "\" clicked" << std::endl;
        return true;
    }

    return false;
}
