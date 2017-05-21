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

class Sprite {
    private:
        SDL2pp::Texture* m_texture;
        SDL2pp::Rect m_rect;
        std::string m_type;
        Color m_color;

    public:
        Sprite(SDL2pp::Texture* texture, SDL2pp::Rect rect, const std::string& type, 
                const SDL2pp::Optional<Color>& color);
        ~Sprite();

        void render(SDL2pp::Renderer& renderer, const SDL2pp::Point& point);

        std::string getType() const;
        void setColor(const Color& color);
};

class SpriteSheet {
    private:
        std::unique_ptr<SDL2pp::Texture> m_texture;
        Json::Value m_sheet_data;
    public:
        SpriteSheet(SDL2pp::Renderer& renderer, const std::string& sprite_sheet_name);
        ~SpriteSheet();

        int getSpriteWidth() const;
        int getSpriteHeight() const;

        Sprite makeSprite(const std::string &spriteName,
                const SDL2pp::Optional<Color> &color);
};

#endif /* SPRITE_HPP */
