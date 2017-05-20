#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2pp/Rect.hh>
#include <SDL2pp/Texture.hh>
#include <json/json.h>
#include <string>
#include <bitset>
#include <memory>
#include "color.hpp"
#include "enum.hpp"

enum class Sprite_flags : unsigned long{
    IS_PLAYER   = 1<<0,
    IS_ENEMY    = 1<<1,
    IS_WALKABLE = 1<<2,
    IS_ITEM     = 1<<3,
};

ENABLE_BITMASK_OPERATORS(Sprite_flags)
const unsigned int MAX_SPRITE_FLAGS = 4;
typedef std::bitset<MAX_SPRITE_FLAGS> flags_for_sprite;

struct Sprite {
    SDL2pp::Texture* texture;
    SDL2pp::Rect rect;
    std::string type;
    Color color;
    flags_for_sprite flags;

    void render(SDL2pp::Renderer& renderer, const SDL2pp::Point& point);
};

class SpriteSheet {
    private:
        std::unique_ptr<SDL2pp::Texture> m_texture;
        Json::Value m_sheet_data;
    public:
        SpriteSheet(SDL2pp::Renderer& renderer, const std::string& sprite_sheet_name);
        ~SpriteSheet() = default;

        Sprite makeSprite(const std::string& spriteName);
        Sprite makeSprite(const std::string& spriteName, Sprite_flags flags);
        Sprite makeSprite(const std::string& spriteName, Color color);
        Sprite makeSprite(const std::string& spriteName, Color color, Sprite_flags flags);
};

#endif /* SPRITE_HPP */
