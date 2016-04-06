#ifndef GAME_HPP
#define GAME_HPP

#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "CreatureFactory.hpp"
#include "Actor.hpp"
#include "Map.hpp"

typedef enum Game_State{
    STARTUP,
    IDLE,
    NEW_TURN,
    VICTORY,
    DEFEAT,
}Game_State;

class Game{
    friend class Map;
    public:
        Game(int screenWidth, int screenHeight);
        ~Game();

        void createRoom(bool first, int x1, int y1, int x2, int y2);
        void placeActor(int x, int y, bool playerStart=false);
        void removeActor(Actor *actor);

        void update();
        void render();
    private:
        TCODList<Actor*> actors;
        TCODRandom *rng;
        Player *player;
        int screenWidth, screenHeight;
        Game_State gameState;
        Map *map;
        CreatureFactory *creatureFactory;
};

extern Game game;

#endif /* GAME_HPP */
