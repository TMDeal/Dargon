#include "Item.hpp"
#include "Game.hpp"

Item::Item()
    : x(0), y(0), beenPicked(false), name("")
{
    game.tiles[x][y].flag.set(HAS_ITEM);
}

Item::Item(int x, int y)
    : x(x), y(y), beenPicked(false), name("")
{
    game.tiles[x][y].flag.set(HAS_ITEM);
}

bool Item::isInFov() const{
    return game.levelMap->isInFov(this->x, this->y);
}

bool Item::pick()
{
    beenPicked = true;
    game.removeItem(this);
    game.tiles[x][y].flag.reset(HAS_ITEM);
}

bool Item::inPlay() const
{
    return !beenPicked;
}

Item::~Item()
{
}

