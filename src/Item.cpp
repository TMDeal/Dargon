#include "Item.hpp"

Item::Item(int x, int y, int ch, TCODColor col, Map *map)
    :super(x, y, ch, col, map)
{
}

void Item::interact(Actor &actor)
{
    use(dynamic_cast<Creature&>(actor));
}

Item::~Item()
{
    delete map;
}
