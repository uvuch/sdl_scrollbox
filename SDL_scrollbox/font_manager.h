#ifndef font_manager_h
#define font_manager_h

#include <map>
#include <string>

#if defined(__APPLE__) || defined(__MACH__)
    #include <SDL2_ttf/SDL_ttf.h>
#else
    #include <SDL2/SDL_ttf.h>
#endif

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