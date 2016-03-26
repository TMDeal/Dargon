#ifndef GAME_HPP
#define GAME_HPP

#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Creature.hpp"
#include "Map.hpp"

static const int GAME_WINDOW_WIDTH = 80;
static const int GAME_WINDOW_HEIGHT = 50;

class Game{
    friend class Map;
    public:
        Game();
        ~Game();

        void update();
        void render();
    private:
        TCODList<Creature *> actors;
        Creature *player;
        int fovRadius;
        bool computeFov;
        Map *map;
};

extern Game game;

#endif /* GAME_HPP */
