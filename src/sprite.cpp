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

void Sprite::render(Renderer& renderer, const Point& point) {
    renderer.SetDrawColor(this->color.r, this->color.g, this->color.b, this->color.a);
    Point sprite_size(this->rect.GetW(), this->rect.GetH());
    renderer.Copy(*texture, this->rect, Rect(point * sprite_size, sprite_size));
}

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

Sprite SpriteSheet::makeSprite(const std::string& spriteName) {
    Sprite sprite;
    Json::Value sprite_data = m_sheet_data["sprites"][spriteName];

    int sprite_x = sprite_data["x"].asInt();
    int sprite_y = sprite_data["y"].asInt();
    int sprite_width = m_sheet_data["sprite-width"].asInt();
    int sprite_height = m_sheet_data["sprite-height"].asInt();

    sprite.texture = m_texture.get();
    sprite.rect = {
        sprite_x * sprite_width,
        sprite_y * sprite_height,
        sprite_width,
        sprite_height
    };
    sprite.type = sprite_data["type"].asString();

    return sprite;
}

Sprite SpriteSheet::makeSprite(const std::string& spriteName, Sprite_flags flags) {
    Sprite sprite = makeSprite(spriteName);

    sprite.flags = flags_for_sprite(static_cast<unsigned long>(flags));

    return sprite;
}

Sprite SpriteSheet::makeSprite(const std::string& spriteName, Color color) {
    Sprite sprite = makeSprite(spriteName);

    sprite.color = color;

    return sprite;
}

Sprite SpriteSheet::makeSprite(const std::string& spriteName, Color color, Sprite_flags flags) {
    Sprite sprite = makeSprite(spriteName);

    sprite.color = color;
    sprite.flags = flags_for_sprite(static_cast<unsigned long>(flags));

    return sprite;
}
