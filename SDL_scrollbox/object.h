//
//  object.h
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/14/23.
//

#ifndef object_h
#define object_h

#include <SDL2/SDL.h>

class Object {
public:
    virtual ~Object() {}
    virtual bool handleEvents(const SDL_Event& event) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};


#endif /* object_h */
