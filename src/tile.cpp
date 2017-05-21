#include <SDL2pp/Renderer.hh>
#include "sprite.hpp"
#include "color.hpp"
#include "tile.hpp"

using SDL2pp::Renderer;

Tile::Tile(const Sprite& sprite)
    :m_sprite(sprite)
{}

Tile::Tile(const Sprite& sprite, Tile_flags flags)
    :m_sprite(sprite), m_flags(flags)
{}

void Tile::render(Renderer& renderer) {
    m_sprite.render(renderer, m_coordinates);
}

void Tile::setColor(const Color& color) {
    m_sprite.setColor(color);
}

bool Tile::hasFlag(Tile_flags flag) const {
    return m_flags.test(flag);
}

void Tile::setFlag(Tile_flags flag) {
    m_flags.set(flag);
}
