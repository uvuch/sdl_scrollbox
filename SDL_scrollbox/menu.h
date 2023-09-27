//  menu.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#ifndef menu_h
#define menu_h

#include "object.h"
#include "menu_item.h"

class Menu: public Object {
public:
    Menu();
    ~Menu();
    
    bool handleEvents(const SDL_Event& event);
    void update();
    void draw();
    
private:
    SDL_Rect m_rect, m_textureRect;
    bool m_bDraggable;

    int m_frameStart;   // first visible item in the list
    int m_frameLength;  // number of items that fit one screen of the menu

    int m_offsetX, m_offsetY;
    static const int m_clickMarginX = 30, m_clickMarginY = 30;
    
    std::vector<MenuItem*> m_menuItems;

    bool onMouseBtnDownHandler(const SDL_Event& event);
    bool onMouseBtnUpHandler(const SDL_Event& event);
    bool onMouseMotionHandler(const SDL_Event& event);
};

#endif /* menu_h */
