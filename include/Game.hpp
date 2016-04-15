#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Enums.hpp"
#include "Coordinates.hpp"
#include "Actor.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "Player.hpp"
#include "Map.hpp"

typedef std::vector<Actor*>::iterator ActorsIter;

class Game{
    public:
        Game(int screenWidth, int screenHeight);
        ~Game();

        void createRoom(bool first, int x1, int y1, int x2, int y2);
        void placeActor(int x, int y, bool playerStart=false);
        ActorsIter removeActor(Actor *actor);

        void update();
        void render();
    public:
        std::vector<Actor*> enemies;
        std::vector<Item*> items;
        TCODRandom *rng;
        Player *player;
        Game_State gameState;
        Map *levelMap;
    private:
        int screenWidth, screenHeight;
};

// define some shortcuts from the game
#define you game.player
#define gameItems game.items
#define gameEnemies game.enemies


extern Game game;

#endif /* GAME_HPP */
