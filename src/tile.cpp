#include <SDL2pp/Renderer.hh>
#include "sprite.hpp"
#include "color.hpp"
#include "tile.hpp"

using SDL2pp::Optional;
using SDL2pp::Renderer;
using SDL2pp::Point;

Tile::Tile(const Point& coordinates, const Optional<Sprite>& sprite)
    :m_sprite(sprite), m_coordinates(coordinates)
{}

Tile::Tile(const Point& coordinates, const Optional<Sprite>& sprite, Tile_flags flags)
    :m_sprite(sprite), m_coordinates(coordinates), m_flags(flags)
{}

Tile::~Tile() = default;

void Tile::render(Renderer& renderer) {
    if(m_sprite) {
        m_sprite->render(renderer, m_coordinates);
    }
}

void Tile::setColor(const Color& color) {
    if(m_sprite) {
        m_sprite->setColor(color);
    }
}

bool Tile::hasFlag(Tile_flags flag) const {
    return m_flags.test(flag);
}

void Tile::setFlag(Tile_flags flag) {
    m_flags.set(flag);
}
