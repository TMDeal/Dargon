#include "Actor.hpp"

Actor::Actor(int x, int y, int ch, const TCODColor col, Map *map)
    : x(x), y(y), ch(ch), col(col)
{
    this->map = map;
}

bool Actor::isAlive() const
{
    return stats->isAlive();
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

bool Actor::move(int x, int y){
    if(map->canWalk(x, y)){
        this->x = x;
        this->y = y;
        return true;
    }
    return false;
}

bool Actor::move(Direction dir)
{
    switch(dir){
        case INVALID_DIRECTION:
            break;
        case DOWN_LEFT_DIAG:
            if(map->canWalk(x-1, y+1)){
                this->x--;
                this->y++;
                return true;
            }
            break;
        case DOWN:
            if(map->canWalk(x, y+1)){
                this->y++;
                return true;
            }
            break;
        case DOWN_RIGHT_DIAG:
            if(map->canWalk(x+1, y+1)){
                this->x++;
                this->y++;
                return true;
            }
            break;
        case LEFT:
            if(map->canWalk(x-1, y)){
                this->x--;
                return true;
            }
            break;
        case STAY:
            break;
        case RIGHT:
            if(map->canWalk(x+1, y)){
                this->x++;
                return true;
            }
            break;
        case UP_LEFT_DIAG:
            if(map->canWalk(x-1, y-1)){
                this->x--;
                this->y--;
                return true;
            }
            break;
        case UP:
            if(map->canWalk(x, y-1)){
                this->y--;
                return true;
            }
            break;
        case UP_RIGHT_DIAG:
            if(map->canWalk(x+1, y-1)){
                this->x--;
                this->y--;
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

void Actor::update()
{
}

void Actor::render() const {
    TCODConsole::root->setChar(x, y, ch);
    TCODConsole::root->setCharForeground(x, y, col);
}
