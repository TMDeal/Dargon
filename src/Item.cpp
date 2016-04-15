#include "Item.hpp"

Item::Item(int x, int y, int ch, TCODColor col)
    :ch(ch), col(col)
{
    pos.set(x, y);
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
