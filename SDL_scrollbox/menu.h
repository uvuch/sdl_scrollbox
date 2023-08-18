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
    Menu() {};
    
    bool handleEvents(const SDL_Event& event);
    void update();
    void draw();
    
private:
    bool onQuitHandler(const SDL_Event& event);
};

#endif /* menu_h */
