#ifndef MAP_HPP
#define MAP_HPP

#include "libtcod/libtcod.hpp"

static const int ROOM_MAX_SIZE = 12;
static const int ROOM_MIN_SIZE = 6;

class Map{
    public:
        Map(int width, int height);
        ~Map();

        bool isWall(int x, int y) const;
        void render() const;
        void dig(int x1, int y1, int x2, int y2);
        void createRoom(bool first, int x1, int y1, int x2, int y2);
    private:
        int width, height;
        TCODMap *map;
        TCODBsp *bsp;
};

#endif /* MAP_HPP */
