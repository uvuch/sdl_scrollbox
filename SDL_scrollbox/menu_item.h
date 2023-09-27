//
//  menu_item.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/18/23.
//

#ifndef menu_item_h
#define menu_item_h

#include "object.h"

class MenuItem: public Object {
public:
    static const int ITEM_HEIGHT = 80;

    MenuItem(std::string label, int x, int y, int w, int h);
    ~MenuItem();

    std::string getLabel() { return m_strLabel; }
    bool handleEvents(const SDL_Event& event);
    void update() {}
    void update(int x, int y);
    void draw();
    
    // bool onMouseBtnDownHandler(const SDL_Event& event);
    // bool onMouseBtnUpHandler(const SDL_Event& event);
    
private:
    std::string m_strLabel;
    SDL_Rect m_rect;
    
    TTF_Font* myFont;
    SDL_Surface* m_pSurface;
    SDL_Texture* m_pTexture;
    SDL_Color white = { 0xFF, 0xFF, 0xFF, 0 };
};

#endif /* menu_item_h */
