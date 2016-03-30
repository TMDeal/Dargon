#include "Dargon.hpp"

Dargon::Dargon(int x, int y, Map *map)
    : super(x, y, 'D', TCODColor::lightBlue, map)
{
    this->stats = new Stats(10, 10, 5, 5);
}

Dargon::~Dargon()
{
}

