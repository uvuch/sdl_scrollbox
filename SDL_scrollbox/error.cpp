//  error.cpp
//  SDL_BasicGameEngine
//
//  Created by Serge Muzyka on 8/14/23.
//

#include "error.h"

Error* Error::s_pInstance = nullptr;

Error* Error::Instance() {
    if (!s_pInstance)
        s_pInstance = new Error();
    
    return s_pInstance;
}

bool Error::message(const char *msg) {
    std::cout << "!! Error: " << msg << std::endl;
    return false;
}
