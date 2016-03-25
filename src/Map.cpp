#include "Map.hpp"
#include "Game.hpp"
#include "BspCallBack.hpp"
#include <algorithm>

Map::Map(int width, int height)
    :width(width), height(height)
{
    tiles = new Tile[width*height];
    map = new TCODMap(width, height);
    bsp = new TCODBsp(0, 0, width, height);
    bsp->splitRecursive(NULL, 8, ROOM_MAX_SIZE, ROOM_MAX_SIZE, 1.5f, 1.5f);
    BspCallBack callBack(*this);
    bsp->traverseInvertedLevelOrder(&callBack, NULL);
}

Map::~Map()
{
    delete[] tiles;
    delete map;
    delete bsp;
}

bool Map::isExplored(int x, int y) const
{
    return tiles[x+y*width].explored;
}

bool Map::isInFov(int x, int y) const
{
    if(map->isInFov(x, y)){
        tiles[x+y*width].explored = true;
        return true;
    }
    return false;
}

void Map::computeFov()
{
    map->computeFov(game.player->x, game.player->y,
            game.fovRadius);
}

void Map::addMonster(int x, int y)
{
    TCODRandom *rng = TCODRandom::getInstance();
    if(rng->getInt(0, 100) < 80){
        game.actors.push(new Actor(x, y, 'O',
                    TCODColor::desaturatedGreen));
    }
    else{
        game.actors.push(new Actor(x, y, 'O',
                    TCODColor::darkerGreen));
    }
}

bool Map::isWall(int x, int y) const
{
    return !map->isWalkable(x, y);
}

bool Map::canWalk(int x, int y) const
{
    if(isWall(x, y)){
        return false;
    }
    for(Actor **iter = game.actors.begin(); iter != game.actors.end(); iter++){
        Actor *actor = *iter;
        if(actor->x == x && actor->y == y){
            return false;
        }
    }
    return true;
}

void Map::dig(int x1, int y1, int x2, int y2)
{
    if(x1 > x2){
        std::swap(x1, x2);
    }
    if(y1 > y2){
        std::swap(y1, y2);
    }

    for(int tilex = x1; tilex <= x2; tilex++){
        for(int tiley = y1; tiley <= y2; tiley++){
            map->setProperties(tilex, tiley, true, true);
        }
    }
}

void Map::createRoom(bool first, int x1, int y1, int x2, int y2)
{
    dig(x1, y1, x2, y2);
    if(first){
       game.player->x = (x1 + x2) / 2;
       game.player->y = (y1 + y2) / 2;
    }
    else{
        TCODRandom *rng = TCODRandom::getInstance();
        if(rng->getInt(0, 3) == 0){
            game.actors.push(new Actor((x1 + x2) / 2, (y1 + y2) / 2, '@',
                        TCODColor::yellow));
        }
    }
}

void Map::render() const
{
    static const TCODColor darkWall(0, 0, 100);
    static const TCODColor darkGround(50, 50, 150);
    static const TCODColor lightWall(130, 110, 50);
    static const TCODColor lightGround(200, 180, 50);

    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            if(isInFov(x, y)){
                TCODConsole::root->setCharBackground(x, y,
                        isWall(x, y) ? lightWall : lightGround);
            }
            else if(isExplored(x, y)){
                TCODConsole::root->setCharBackground(x, y,
                        isWall(x, y) ? darkWall : darkGround);
            }
        }
    }

}

