//  menu.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#ifndef menu_h
#define menu_h

#include "game.h"
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
    SDL_Rect m_rect;
    SDL_Color m_color;
    
    int m_frameStart;
    int m_frameLength;
    static const int ITEM_HEIGHT = 40;
    
    int mouse_x, mouse_y;
    bool clicked;
    
    std::vector<MenuItem*> m_menuItems;

    bool onMouseBtnDownHandler(const SDL_Event& event);
    bool onMouseBtnUpHandler(const SDL_Event& event);
    bool onMouseMotionHandler(const SDL_Event& event);
};

#endif /* menu_h */
