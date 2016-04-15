#ifndef MAP_HPP
#define MAP_HPP

#include <algorithm>
#include "libtcod/libtcod.hpp"
#include "Enums.hpp"
#include "Actor.hpp"

static const int ROOM_MAX_SIZE = 12;
static const int ROOM_MIN_SIZE = 6;
static const int MAX_ROOM_MONSTERS = 3;
static const int FOVRADIUS = 10;

struct Tile{
    bool explored;
    Actor *actor;
    Tile() : explored(false), actor(NULL){}
};

class Map{
    public:
        Map(int width, int height);
        ~Map();

        void generate();
        bool isWall(int x, int y) const;
        bool canPlace(int x, int y) const;
        void dig(int x1, int y1, int x2, int y2);
        void setActorOnTile(Actor &actor, int x, int y);
        Actor *getActorOnTile(int x, int y);
        void removeActorOnTile(int x, int y);
        bool isActorOnTile(int x, int y) const;

        bool isInFov(int x, int y) const;
        bool isExplored(int x, int y) const;
        void computeFov(int x, int y);

        void render() const;
    private:
        int width, height;
        Tile *tiles;
        TCODMap *map;
        TCODBsp *bsp;
};

#endif /* MAP_HPP */
