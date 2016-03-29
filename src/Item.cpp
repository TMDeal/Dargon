#include "Item.hpp"

Item::Item(int x, int y, int ch, TCODColor col, Map *map)
    : x(x), y(y), ch(ch), col(col)
{
    this->map = map;
}

Item::~Item()
{
    delete map;
}

void Item::render()
{
}
