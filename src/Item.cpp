#include "Item.hpp"

Item::Item(int x, int y, int ch, TCODColor col, Map *map)
    :super(x, y, ch, col, map)
{
}

Item::~Item()
{
    delete map;
}
