//
//  common.h
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 9/2/23.
//

#ifndef common_h
#define common_h

#include <SDL2/SDL.h>

#if defined(__APPLE__) || defined(__MACH__)
    #include <SDL2_ttf/SDL_ttf.h>
    #include <SDL2_image/SDL_image.h>
#else
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_image.h>
#endif

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "error.h"

#endif /* common_h */
