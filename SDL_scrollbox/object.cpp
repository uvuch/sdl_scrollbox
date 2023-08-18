//
//  object.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/14/23.
//

#include "object.h"

bool Object::handleEvents(const SDL_Event& event) {
    for (const auto &map_element : m_eventHandlers) {
        Uint32 eventTypeToHandle = map_element.first;
        eventHandler handler = map_element.second;
        
        if (event.type == eventTypeToHandle)
            return handler(event);
    }
    
    return false;
}
