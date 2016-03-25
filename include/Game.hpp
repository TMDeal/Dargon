#ifndef GAME_HPP
#define GAME_HPP

#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Actor.hpp"
#include "Map.hpp"

class Game{
    friend class Map;
    public:
        Game();
        ~Game();

        void update();
        void render();
    private:
        TCODList<Actor *> actors;
        Actor *player;
        Map *map;
};

extern Game game;

#endif /* GAME_HPP */
