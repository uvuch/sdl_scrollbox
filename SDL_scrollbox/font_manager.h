#ifndef font_manager_h
#define font_manager_h

#include <map>
#include <string>
#include <SDL_ttf.h>

class FontManager {
public:
    static FontManager& Instance();
    TTF_Font* get(std::string id);
    bool load(std::string fontFileName, std::string id, int size);

private:
    FontManager();
    ~FontManager();

    std::map<std::string, TTF_Font*> m_fontMap;
};

#endif