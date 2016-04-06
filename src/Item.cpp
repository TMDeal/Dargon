#include "Item.hpp"

Item::Item(int x, int y, int ch, TCODColor col, Map *map)
    :super(x, y, ch, col, map), hasBeenPicked(false)
{
}

void Item::interact(Actor &actor)
{
    use(dynamic_cast<Creature&>(actor));
}

void Item::update()
{
}

bool Item::inPlay() const
{
    return !hasBeenPicked;
}

Item::~Item()
{
    delete map;
}
