//
//  menu_item.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/18/23.
//

#ifndef menu_item_h
#define menu_item_h

#include "object.h"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <string>

class MenuItem: public Object {
public:
    static const int ITEM_HEIGHT = 80;
    static const int ITEM_WIDTH = 400;
    static int s_offsetX, s_offsetY;
    int m_positionInFrame;

    MenuItem(std::string label);
    // MenuItem(std::string label, int x, int y, int w, int h);
    ~MenuItem();

    std::string getLabel() { return m_strLabel; }
    bool handleEvents(const SDL_Event& event);
    void update();
    void draw();
    
    bool onMouseBtnDownHandler(const SDL_Event& event);
    
private:
    std::string m_strLabel;
    SDL_Rect m_rect;
    
    SDL_Texture* m_pTexture;
    // SDL_Surface* m_pSurface;
    //SDL_Color white = { 0xFF, 0xFF, 0xFF, 0 };
};

#endif /* menu_item_h */
