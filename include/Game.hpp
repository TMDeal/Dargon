#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <bitset>
#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Actor.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include "Map.hpp"
#include "Gui.hpp"

using std::vector;

typedef std::vector<Monster*>::iterator MonsterIter;
typedef std::vector<Item*>::iterator ItemIter;

typedef enum Game_State{
    STARTUP,
    IDLE,
    NEW_TURN,
    VICTORY,
    DEFEAT,
}Game_State;

typedef enum Tile_Flag{
    SAFE,
    HAS_MONSTER,
    HAS_PLAYER,
    HAS_ITEM,
}Tile_Flag;

struct Tile{
    bool explored;
    std::bitset<4> flag;

    Tile() : explored(false), flag("0001"){}
};

class Game{
    public:
        Game(int screenWidth, int screenHeight);
        ~Game();

        void update();
        void render();

        Item* findItem(const int &x, const int &y);
        Monster* findMonster(const int &x, const int &y);
        ItemIter removeItem(Item *item);
        MonsterIter removeMonster(Monster *mon);
    public:
        Map *levelMap;
        Tile **tiles;
        Game_State gameState;
        Player *player;
        Gui *gui;
        TCOD_key_t input;
        TCOD_mouse_t mouse;
        std::vector<Monster*> monsters;
        std::vector<Item*> items;
};

extern Game game;

#endif /* GAME_HPP */
