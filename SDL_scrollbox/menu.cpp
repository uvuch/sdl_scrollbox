//
//  menu.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#include "menu.h"

Menu::Menu() {
    m_rect.x = 500;
    m_rect.y = 200;
    m_rect.w = 1250;
    m_rect.h = 775;

    m_textureRect.x = 140;
    m_textureRect.y = 465;
    m_textureRect.w = 1220;
    m_textureRect.h = 775;
    
    TextureManager::Instance().load("assets/panel.png", "panel", Renderer::instance());

    m_frameLength = 6;
    m_frameStart = 0;
    
    m_bDraggable = false;
    
    m_menuItems.push_back(new MenuItem("Option 1"));
    m_menuItems.push_back(new MenuItem("Option 2"));
    m_menuItems.push_back(new MenuItem("Option 3"));
    m_menuItems.push_back(new MenuItem("Option 4"));
    m_menuItems.push_back(new MenuItem("Option 5"));
    m_menuItems.push_back(new MenuItem("Option 6"));
    m_menuItems.push_back(new MenuItem("Option 7"));
    m_menuItems.push_back(new MenuItem("Option 8"));
    m_menuItems.push_back(new MenuItem("Option 9"));
    m_menuItems.push_back(new MenuItem("Option 10"));

    for(int i = m_frameStart; i < m_frameStart + m_frameLength && i < m_menuItems.size(); i++)
        m_menuItems[i]->m_positionInFrame = i - m_frameStart;
    
    MenuItem::s_offsetX = m_rect.x + (m_rect.w - MenuItem::ITEM_WIDTH) / 2;
    MenuItem::s_offsetY = m_rect.y + 150;
}

Menu::~Menu() {    
    for(const auto& el : m_menuItems) delete el;
    m_menuItems.clear();
}

bool Menu::handleEvents(const SDL_Event& event) {
    for(std::vector<MenuItem*>::size_type i = m_frameStart; i != m_menuItems.size() && i < m_frameStart + m_frameLength; i++ ) {
        if (m_menuItems[i]->handleEvents(event))
            return true;
    }
    
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            return this->onMouseBtnDownHandler(event);
        case SDL_MOUSEBUTTONUP:
            return this->onMouseBtnUpHandler(event);
        case SDL_MOUSEMOTION:
            return this->onMouseMotionHandler(event);
    }

    return false;
}

void Menu::update() {
    for(std::vector<MenuItem*>::size_type i = m_frameStart; i != m_menuItems.size() && i < m_frameStart + m_frameLength; i++)
        m_menuItems[i]->update();
}

void Menu::draw() {
    SDL_RenderCopy(Renderer::instance(), TextureManager::Instance().get("panel"), &m_textureRect, &m_rect);
    
    for(std::vector<MenuItem*>::size_type i = m_frameStart; i != m_menuItems.size() && i < m_frameStart + m_frameLength; i++)
        m_menuItems[i]->draw();
}

bool Menu::onMouseBtnDownHandler(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT &&
        event.button.x >= m_rect.x + m_clickMarginX && event.button.x <= m_rect.x + m_rect.w - m_clickMarginX &&
        event.button.y >= m_rect.y + m_clickMarginY && event.button.y <= m_rect.y + m_rect.h - m_clickMarginY)
    {
        m_bDraggable = true;
        m_offsetX = event.button.x - m_rect.x;
        m_offsetY = event.button.y - m_rect.y;
        return true;
    }

    return false;
}

bool Menu::onMouseBtnUpHandler(const SDL_Event& event) {
    m_bDraggable = false;
    return false;
}

bool Menu::onMouseMotionHandler(const SDL_Event& event) {
    if (!m_bDraggable) return false;

    m_rect.x = event.motion.x - m_offsetX;
    m_rect.y = event.motion.y - m_offsetY;

    MenuItem::s_offsetX = m_rect.x + (m_rect.w - MenuItem::ITEM_WIDTH) / 2;
    MenuItem::s_offsetY = m_rect.y + 150;
    return true;
}
