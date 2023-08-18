//
//  menu.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#include "menu.h"
#include <iostream>

Menu::Menu() {
    m_rect.x = m_rect.y = 100;
    m_rect.w = m_rect.h = 200;
    
    m_color.r = 0;
    m_color.g = 200;
    m_color.b = 0;
    m_color.a = 255;
    
    clicked = false;
}

bool Menu::handleEvents(const SDL_Event& event) {
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
    if (clicked) {
        m_color.g = 0;
        m_color.b = 200;
    } else {
        m_color.g = 200;
        m_color.b = 0;
    }
}

void Menu::draw(SDL_Renderer *pRenderer) {
    SDL_SetRenderDrawColor(pRenderer, m_color.r, m_color.g, m_color.b, m_color.a); // RGBA
    SDL_RenderFillRect(pRenderer, &m_rect);
}

bool Menu::onMouseBtnDownHandler(const SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT &&
        event.button.x >= m_rect.x && event.button.x <= m_rect.x + m_rect.w &&
        event.button.y >= m_rect.y && event.button.y <= m_rect.y + m_rect.h)
    {
        clicked = true;
        mouse_x = event.button.x - m_rect.x;
        mouse_y = event.button.y - m_rect.y;
        std::cout << "Clicked inside the menu" << std::endl;
        return true;
    }

    return false;
}

bool Menu::onMouseBtnUpHandler(const SDL_Event& event) {
    clicked = false;
    return false;
}

bool Menu::onMouseMotionHandler(const SDL_Event& event) {
    if (clicked) {
        m_rect.x = event.motion.x - mouse_x;
        m_rect.y = event.motion.y - mouse_y;
        return true;
    }
    
    return false;
}
