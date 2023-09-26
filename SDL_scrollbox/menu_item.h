//
//  menu_item.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/18/23.
//

#ifndef menu_item_h
#define menu_item_h

#include <SDL2/SDL.h>

#if defined(__APPLE__) || defined(__MACH__)
    #include <SDL2_ttf/SDL_ttf.h>
#else
    #include <SDL2/SDL_ttf.h>
#endif

#include <string>

class MenuItem {
public:
    MenuItem(std::string label, int x, int y, int w, int h);

    std::string getLabel() { return m_strLabel; }
    bool handleEvents(const SDL_Event& event);
    void update(int x, int y);
    void draw(SDL_Renderer *pRenderer);
    
    bool onMouseBtnDownHandler(const SDL_Event& event);
    bool onMouseBtnUpHandler(const SDL_Event& event);
    
private:
    std::string m_strLabel;
    SDL_Rect m_rect;
    
    TTF_Font* myFont;
    SDL_Surface* m_pSurface;
    SDL_Color white = { 0xFF, 0xFF, 0xFF, 0 };
};

#endif /* menu_item_h */
