#ifndef GAME_HPP
#define GAME_HPP

#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Actor.hpp"
#include "Map.hpp"

static const int GAME_WINDOW_WIDTH = 80;
static const int GAME_WINDOW_HEIGHT = 50;

class Game{
    friend class Map;
    public:
        Game();
        ~Game();

        void createRoom(bool first, int x1, int y1, int x2, int y2);
        void placeActor(int x, int y, bool playerStart=false);

        void update();
        void render();
    private:
        TCODList<Actor *> actors;
        TCODRandom *rng;
        Actor *player;
        bool computeFov;
        Map *map;
};

extern Game game;

#endif /* GAME_HPP */
