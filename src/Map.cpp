#include "Map.hpp"
#include "BspCallBack.hpp"
#include <algorithm>

Map::Map(int width, int height)
    :width(width), height(height)
{
    tiles = new Tile[width*height];
    map = new TCODMap(width, height);
    bsp = new TCODBsp(0, 0, width, height);
}

Map::~Map()
{
    delete[] tiles;
    delete map;
    delete bsp;
}

void Map::generate(){
    bsp->removeSons();
    bsp->splitRecursive(NULL, 8, ROOM_MAX_SIZE, ROOM_MAX_SIZE, 1.5f, 1.5f);
    BspCallBack callBack(*this);
    bsp->traverseInvertedLevelOrder(&callBack, NULL);
}

void Map::setActorOnTile(Actor &actor, int x, int y)
{
    tiles[x+y*width].actor = &actor;
}

void Map::removeActorOnTile(int x, int y)
{
    tiles[x+y*width].actor = NULL;
}

bool Map::isActorOnTile(int x, int y) const
{
    return tiles[x+y*width].actor != NULL;
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

void Map::computeFov(int x, int y)
{
    map->computeFov(x, y, FOVRADIUS);
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
        if(actor->collides(x, y)){
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

