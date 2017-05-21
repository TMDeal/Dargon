#include <iostream>
#include <SDL2pp/Surface.hh>
#include <SDL2pp/Texture.hh>
#include <SDL2pp/Renderer.hh>
#include <SDL2pp/Point.hh>
#include <fstream>
#include "res_paths.hpp"
#include "color.hpp"
#include "sprite.hpp"

using namespace SDL2pp;

/*
 * Sprite Definitions
 */
Sprite::Sprite(Texture* texture, Rect rect, const std::string& type, 
        const Optional<Color>& color, const Optional<Sprite_flags>& flags)
    :m_texture(texture),
    m_rect(rect),
    m_type(type),
    m_color(color.value_or(Color(255, 255, 255))),
    m_flags(flags.value_or(Sprite_flags::IS_WALKABLE))
{}

Sprite::~Sprite() = default;

std::string Sprite::getType() const {
    return m_type;
}

bool Sprite::hasFlag(Sprite_flags flag) const {
    return m_flags.test(flag);
}

void Sprite::setColor(const Color& color) {
    m_color = color;
}

void Sprite::render(Renderer& renderer, const Point& point) {
    m_texture->SetColorMod(m_color.r, m_color.g, m_color.b);
    Point sprite_size(m_rect.GetW(), m_rect.GetH());
    renderer.Copy(*m_texture, m_rect, Rect(point * sprite_size, sprite_size));
}

/*
 * SpriteSheet Definitions
 */
SpriteSheet::SpriteSheet(Renderer& renderer, const std::string& sprite_sheet_name) {
    SDL2pp::Surface sprite_sheet_surface(RES_DIRECTORY + sprite_sheet_name + ".png");
    SDL2pp::Surface::LockHandle lock = sprite_sheet_surface.Lock();
    Color colorKey(255, 0, 255);
    sprite_sheet_surface.SetColorKey(true, SDL_MapRGB(&lock.GetFormat(), colorKey.r, colorKey.g, colorKey.b));
    m_texture = std::make_unique<Texture>(renderer, sprite_sheet_surface);

    Json::Reader json_reader;
    std::ifstream data_file(SPRITE_DATA_DIRECTORY + sprite_sheet_name + ".json");
    json_reader.parse(data_file, m_sheet_data);
}

SpriteSheet::~SpriteSheet() = default;

Sprite SpriteSheet::makeSprite(const std::string& spriteName,
        const Optional<Color>& color, const Optional<Sprite_flags>& flags)
{
    Json::Value sprite_data = m_sheet_data["sprites"][spriteName];

    int sprite_x = sprite_data["x"].asInt();
    int sprite_y = sprite_data["y"].asInt();
    int sprite_width = m_sheet_data["sprite-width"].asInt();
    int sprite_height = m_sheet_data["sprite-height"].asInt();

    Texture* sprite_texture = m_texture.get();

    Rect sprite_rect = {
        sprite_x * sprite_width,
        sprite_y * sprite_height,
        sprite_width,
        sprite_height
    };

    std::string sprite_type = sprite_data["type"].asString();

    Sprite sprite(sprite_texture, sprite_rect, sprite_type, color, flags);
    return sprite;
}
