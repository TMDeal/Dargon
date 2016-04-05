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
    defender.takeDamage(stats->getAttackRoll());
}

int Creature::defend(Creature &attacker)
{
}

void Creature::interact(Actor &actor)
{
    attack(dynamic_cast<Creature&>(actor));
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
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x+1, this->y-1);
                return true;
            }
            break;
        case DOWN:
            if(map->canWalk(x, y+1)){
                this->y++;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x, this->y-1);
                return true;
            }
            break;
        case DOWN_RIGHT_DIAG:
            if(map->canWalk(x+1, y+1)){
                this->x++;
                this->y++;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x-1, this->y-1);
                return true;
            }
            break;
        case LEFT:
            if(map->canWalk(x-1, y)){
                this->x--;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x+1, this->y);
                return true;
            }
            break;
        case STAY:
            break;
        case RIGHT:
            if(map->canWalk(x+1, y)){
                this->x++;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x-1, this->y);
                return true;
            }
            break;
        case UP_LEFT_DIAG:
            if(map->canWalk(x-1, y-1)){
                this->x--;
                this->y--;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x+1, this->y+1);
                return true;
            }
            break;
        case UP:
            if(map->canWalk(x, y-1)){
                this->y--;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x, this->y+1);
                return true;
            }
            break;
        case UP_RIGHT_DIAG:
            if(map->canWalk(x+1, y-1)){
                this->x--;
                this->y--;
                map->setActorOnTile(*this, this->x, this->y);
                map->removeActorOnTile(this->x+1, this->y+1);
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
