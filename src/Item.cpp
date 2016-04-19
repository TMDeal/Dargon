#include "Item.hpp"

Item::Item(int x, int y, int ch, TCODColor col)
    :x(x), y(y), ch(ch), col(col)
{
}

void Item::interact(Actor &actor)
{
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
}
