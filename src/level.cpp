#include <SDL2pp/Optional.hh>
#include "level.hpp"
#include "sprite.hpp"
#include "color.hpp"

using SDL2pp::NullOpt;
using SDL2pp::Renderer;
using SDL2pp::Point;

Level::Level(SpriteSheet& sprite_sheet, int width, int height)
    :m_width(width), m_height(height)
{
    Color sprite_color(120, 62, 13);
    Sprite tile_sprite = sprite_sheet.makeSprite("pebbles", sprite_color);
    int x_size = m_width / sprite_sheet.getSpriteWidth();
    int y_size = m_height / sprite_sheet.getSpriteHeight();

    for(int i = 0; i < x_size * y_size; i++) {
        int x = i % x_size;
        int y = 0 + (i / x_size);
        Point coordinates(x, y);

        Tile tile(coordinates, tile_sprite);
        m_tiles.push_back(tile);
    }
}

Level::~Level() = default;

void Level::render(Renderer& renderer) {
    for(auto tile : m_tiles) {
        tile.render(renderer);
    }
}

Tile Level::getTile(const Point& coordinate) const {
    return m_tiles.at(coordinate.x + coordinate.y * m_width);
}

int Level::getWidth() const {
    return m_width;
}

int Level::getHeight() const {
    return m_height;
}
