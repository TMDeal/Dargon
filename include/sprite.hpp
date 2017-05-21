#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2pp/Rect.hh>
#include <json/json.h>
#include <string>
#include <bitset>
#include <memory>
#include "color.hpp"

namespace SDL2pp {
    class Renderer;
    class Texture;
}

enum Sprite_flags {
    IS_PLAYER   = 1<<0,
    IS_ENEMY    = 1<<1,
    IS_WALKABLE = 1<<2,
    IS_ITEM     = 1<<3,
};

const unsigned int MAX_SPRITE_FLAGS = 4;
typedef std::bitset<MAX_SPRITE_FLAGS> sprite_bitset;

class Sprite {
    private:
        SDL2pp::Texture* m_texture;
        SDL2pp::Rect m_rect;
        std::string m_type;
        Color m_color;
        sprite_bitset m_flags;

    public:
        Sprite(SDL2pp::Texture* texture, SDL2pp::Rect rect, const std::string& type, 
                const SDL2pp::Optional<Color>& color, const SDL2pp::Optional<Sprite_flags>& flags);
        ~Sprite();

        void render(SDL2pp::Renderer& renderer, const SDL2pp::Point& point);

        std::string getType() const;
        bool hasFlag(Sprite_flags flag) const;
        void setColor(const Color& color);
};

class SpriteSheet {
    private:
        std::unique_ptr<SDL2pp::Texture> m_texture;
        Json::Value m_sheet_data;
    public:
        SpriteSheet(SDL2pp::Renderer& renderer, const std::string& sprite_sheet_name);
        ~SpriteSheet();

        Sprite makeSprite(const std::string &spriteName,
                const SDL2pp::Optional<Color> &color,
                const SDL2pp::Optional<Sprite_flags> &flags);
};

#endif /* SPRITE_HPP */
