#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2pp/Point.hh>
#include <vector>
#include <bitset>
#include "sprite.hpp"

struct Color;

namespace SDL2pp {
    class Renderer;
}

enum Tile_flags {
    HAS_PLAYER = 1<<0,
    WALKABLE   = 1<<1
};

const int MAX_TILE_FLAGS = 2;
typedef std::bitset<MAX_TILE_FLAGS> tile_bitset;

class Tile {
    private:
        SDL2pp::Point m_coordinates;
        Sprite m_sprite;
        tile_bitset m_flags;
    public:
        Tile(const Sprite& sprite);
        Tile(const Sprite& sprite, Tile_flags flags);
        ~Tile();

        void render(SDL2pp::Renderer& Renderer);
        void setColor(const Color& color);
        bool hasFlag(Tile_flags flag) const;
        void setFlag(Tile_flags flag);
};

#endif /* TILE_HPP */
