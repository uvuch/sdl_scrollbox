//
//  renderer.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 9/2/23.
//

#ifndef renderer_h
#define renderer_h

#include "common.h"

class Renderer {
public:
    static bool init(char* windowTitle, int x, int y, int w, int h, int flags);
    static SDL_Renderer* instance();
    static void free();
    
private:
    Renderer(char* windowTitle, int x, int y, int w, int h, int flags);
    ~Renderer();

    static Renderer* s_pRenderer;
    
    SDL_Renderer* m_pRenderer;
    SDL_Window* m_pWindow;
};

#endif /* renderer_h */
