//
//  menu.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#include "menu.h"

Menu::Menu() {
    m_rect.x = m_rect.y = 100;
    m_rect.w = 300;
    m_rect.h = 600;
    
    m_color.r = 0;
    m_color.g = 200;
    m_color.b = 0;
    m_color.a = 255;
    
    // m_frameLength = 10;
    // m_frameStart = 0;
    
    // clicked = false;
    
    // m_menuItems.push_back(new MenuItem("Option 1",  m_rect.x + 5, m_rect.y +  50, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 2",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 1, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 3",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 2, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 4",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 3, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 5",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 4, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 6",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 5, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 7",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 6, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 8",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 7, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 9",  m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 8, m_rect.w - 10, ITEM_HEIGHT));
    // m_menuItems.push_back(new MenuItem("Option 10", m_rect.x + 5, m_rect.y + ITEM_HEIGHT * 9, m_rect.w - 10, ITEM_HEIGHT));
}

Menu::~Menu() {
    std::cout << "Deleting Menu..." << std::endl;
    // for(std::vector<MenuItem*>::size_type i = 0; i != m_menuItems.size(); i++ ) {
    //     std::cout << "Deleted menu item \"" << m_menuItems[i]->getLabel() << "\"" << std::endl;
    //     delete m_menuItems[i];

    // }

    // m_menuItems.clear();
    std::cout << "Menu object has been deleted." << std::endl;
}

bool Menu::handleEvents(const SDL_Event& event) {
    // for(std::vector<MenuItem*>::size_type i = m_frameStart; i != m_menuItems.size() && i < m_frameStart + m_frameLength; i++ ) {
    //     if (m_menuItems[i]->handleEvents(event))
    //         return true;
    // }
    
    // switch(event.type) {
    //     case SDL_MOUSEBUTTONDOWN:
    //         return this->onMouseBtnDownHandler(event);
    //     case SDL_MOUSEBUTTONUP:
    //         return this->onMouseBtnUpHandler(event);
    //     case SDL_MOUSEMOTION:
    //         return this->onMouseMotionHandler(event);
    // }

    return false;
}

void Menu::update() {
    // if (clicked) {
    //     m_color.g = 0;
    //     m_color.b = 200;
    // } else {
    //     m_color.g = 200;
    //     m_color.b = 0;
    // }
    
    // for(std::vector<MenuItem*>::size_type i = m_frameStart; i != m_menuItems.size() && i < m_frameStart + m_frameLength; i++ ) {
    //     m_menuItems[i]->update(m_rect.x + 5, m_rect.y + 50 + ((int) i - m_frameStart) * ITEM_HEIGHT);
    // }
}

void Menu::draw() {
    SDL_Renderer* pRenderer = Renderer::instance();
    SDL_SetRenderDrawColor(pRenderer, m_color.r, m_color.g, m_color.b, m_color.a); // RGBA
    SDL_RenderFillRect(pRenderer, &m_rect);
    
    // for(std::vector<MenuItem*>::size_type i = m_frameStart; i != m_menuItems.size() && i < m_frameStart + m_frameLength; i++ )
    //     m_menuItems[i]->draw();
}

// bool Menu::onMouseBtnDownHandler(const SDL_Event& event) {
//     if (event.button.button == SDL_BUTTON_LEFT &&
//         event.button.x >= m_rect.x && event.button.x <= m_rect.x + m_rect.w &&
//         event.button.y >= m_rect.y && event.button.y <= m_rect.y + m_rect.h)
//     {
//         clicked = true;
//         mouse_x = event.button.x - m_rect.x;
//         mouse_y = event.button.y - m_rect.y;
//         std::cout << "Clicked inside the menu" << std::endl;
//         return true;
//     }

//     return false;
// }

// bool Menu::onMouseBtnUpHandler(const SDL_Event& event) {
//     clicked = false;
//     return false;
// }

// bool Menu::onMouseMotionHandler(const SDL_Event& event) {
//     if (clicked) {
//         m_rect.x = event.motion.x - mouse_x;
//         m_rect.y = event.motion.y - mouse_y;
//         return true;
//     }
    
//     return false;
// }
