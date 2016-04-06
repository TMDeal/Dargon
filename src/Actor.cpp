#include "Actor.hpp"

Actor::Actor(int x, int y, int ch, const TCODColor col, Map *map)
    : x(x), y(y), ch(ch), col(col)
{
    this->map = map;
    map->setActorOnTile(*this, this->x, this->y);
}

Actor::~Actor()
{
}

bool Actor::isInFov() const{
    return map->isInFov(this->x, this->y);
}

bool Actor::collides(int x, int y){
    return this->x == x && this->y == y;
}

void Actor::computeFov()
{
    map->computeFov(this->x, this->y);
}

bool Actor::place(int x, int y){
    if(map->canWalk(x, y)){
        map->setActorOnTile(*this, x, y);
        map->removeActorOnTile(this->x, this->y);
        this->x = x;
        this->y = y;
        return true;
    }
    return false;
}

void Actor::render() const {
    TCODConsole::root->setChar(x, y, ch);
    TCODConsole::root->setCharForeground(x, y, col);
}
