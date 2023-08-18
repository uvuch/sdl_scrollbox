//
//  object.h
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/14/23.
//

#ifndef object_h
#define object_h

#include <SDL2/SDL.h>
#include <map>

typedef bool (*eventHandler)(const SDL_Event&);

class Object {
public:
    bool handleEvents(const SDL_Event& event);
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
    std::map<Uint32, eventHandler> m_eventHandlers;
};

#endif /* object_h */
