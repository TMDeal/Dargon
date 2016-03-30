#include "Creature.hpp"

Creature::Creature(int x, int y, int ch, TCODColor col, Map *map)
    : super(x, y, ch, col, map)
{
}

Creature::~Creature()
{
    delete stats;
}

void Creature::attack(Creature &defender)
{
}

int Creature::defend(Creature &attacker)
{
}

void Creature::update()
{
    if(!stats->isAlive()){
        die();
    }
}

bool Creature::move(Direction dir)
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


bool Creature::isAlive() const
{
    return stats->isAlive();
}

void Creature::heal(int healAmount)
{
    stats->heal(healAmount);
}

void Creature::takeDamage(int damage)
{
    stats->takeDamage(damage);
}
