//
//  menu.cpp
//  SDL_scrollbox
//
//  Created by Serge Muzyka on 8/17/23.
//

#include "menu.h"
#include <iostream>

bool Menu::handleEvents(const SDL_Event& event) {
    switch(event.type) {
        case SDL_QUIT:
            return this->onQuitHandler(event);
    }

    return false;
}

void Menu::update() {}
void Menu::draw() {}

bool Menu::onQuitHandler(const SDL_Event& event) {
    std::cout << "Menu handled SDL_QUIT event" << std::endl;
    return false;
}
