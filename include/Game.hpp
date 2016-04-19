#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Enums.hpp"
#include "Actor.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include "Map.hpp"

using std::vector;

typedef std::vector<Monster*>::iterator MonsterIter;
typedef std::vector<Item*>::iterator ItemIter;

struct Tile{
    bool explored;
    Tile_Flag flag;

    Tile() : explored(false), flag(SAFE){}
};

class Game{
    public:
        Game(int screenWidth, int screenHeight);
        ~Game();

        template<class T>
        typename vector<T>::iterator findAtCoordinate(vector<T*> objs, const int &x, const int &y);
        template<class T>
        typename vector<T>::iterator remove(vector<T*> objs, T obj);

        void update();
        void render();
    public:
        Map *levelMap;
        Tile **tiles;
        Game_State gameState;
        Player *player;
        std::vector<Monster*> monsters;
        std::vector<Item*> items;
    private:
        int screenWidth, screenHeight;
};

extern Game game;

#endif /* GAME_HPP */
