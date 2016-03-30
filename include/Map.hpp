#ifndef MAP_HPP
#define MAP_HPP

#include "libtcod/libtcod.hpp"
#include "Actor.hpp"

static const int ROOM_MAX_SIZE = 12;
static const int ROOM_MIN_SIZE = 6;
static const int MAX_ROOM_MONSTERS = 3;
static const int FOVRADIUS = 10;

class Actor;

// define directions according to keypad keys
typedef enum Direction{
    INVALID_DIRECTION,   // 0
    DOWN_LEFT_DIAG,      // 1
    DOWN,                // 2
    DOWN_RIGHT_DIAG,     // 3
    LEFT,                // 4
    STAY,                // 5
    RIGHT,               // 6
    UP_LEFT_DIAG,        // 7
    UP,                  // 8
    UP_RIGHT_DIAG,       // 9
}Direction;

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
        bool canWalk(int x, int y) const;
        void dig(int x1, int y1, int x2, int y2);
        void createRoom(bool first, int x1, int y1, int x2, int y2);

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
