#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include "tile.hpp"

namespace SDL2pp {
    class Renderer;
    class Point;
}

class Level {
    private:
        int m_width, m_height;
        std::vector<Tile> m_tiles;
    public:
        Level(SpriteSheet& sprite_sheet, int width, int height);
        ~Level();

        void render(SDL2pp::Renderer& renderer);
        Tile getTile(const SDL2pp::Point& coordinate) const;
        int getWidth() const;
        int getHeight() const;
};

#endif /* LEVEL_HPP */
