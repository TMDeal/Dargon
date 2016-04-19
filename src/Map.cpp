#include "Map.hpp"
#include "BspCallBack.hpp"

Map::Map(int width, int height)
    :width(width), height(height)
{
    map = new TCODMap(width, height);
    bsp = new TCODBsp(0, 0, width, height);
}

Map::~Map()
{
}

void Map::generate(){
    bsp->removeSons();
    bsp->splitRecursive(NULL, 8, ROOM_MAX_SIZE, ROOM_MAX_SIZE, 1.5f, 1.5f);
    BspCallBack callBack(*this);
    bsp->traverseInvertedLevelOrder(&callBack, NULL);
}

bool Map::isExplored(int x, int y) const
{
    return game.tiles[x][y].explored;
}

bool Map::isInFov(int x, int y) const
{
    if(map->isInFov(x, y)){
        game.tiles[x][y].explored = true;
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

bool Map::canPlace(int x, int y) const
{
    if(isWall(x, y)){
        return false;
    }
    if(game.tiles[x][y].flag != SAFE){
        return false;
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

