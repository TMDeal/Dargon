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
    int newX = this->x;
    int newY = this->y;

    switch(dir){
        case DOWN_LEFT_DIAG:
            newX--;
            newY++;
            break;
        case DOWN:
            newY++;
            break;
        case DOWN_RIGHT_DIAG:
            newX++;
            newY++;
            break;
        case LEFT:
            newX--;
            break;
        case STAY:
            return false;
            break;
        case RIGHT:
            newX++;
            break;
        case UP_LEFT_DIAG:
            newX--;
            newY--;
            break;
        case UP:
            newY--;
            break;
        case UP_RIGHT_DIAG:
            newX++;
            newY--;
            break;
        default:
            return false;
            break;
    }
    if(map->canWalk(newX, newY)){
        int oldX = this->x;
        int oldY = this->y;
        this->x = newX;
        this->y = newY;
        map->setActorOnTile(*this, this->x, this->y);
        map->removeActorOnTile(oldX, oldY);
        return true;
    }
    else if(map->isActorOnTile(newX, newY)){
        interact(map->getActorOnTile(newX, newY));
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
    stats->displayeStats();
}
