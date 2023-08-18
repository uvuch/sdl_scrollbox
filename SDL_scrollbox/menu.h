//  menu.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#ifndef menu_h
#define menu_h

#include "object.h"

class Menu: public Object {
public:
    Menu();
    
    bool handleEvents(const SDL_Event& event);
    void update();
    void draw(SDL_Renderer *pRenderer);
    
private:
    SDL_Rect m_rect;
    SDL_Color m_color;
    bool clicked;
    bool onMouseBtnDownHandler(const SDL_Event& event);
    bool onMouseBtnUpHandler(const SDL_Event& event);
};

#endif /* menu_h */
