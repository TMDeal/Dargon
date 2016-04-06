#include "Potion.hpp"

Potion::Potion(int x, int y, Map *map)
    :super(x, y, '!', TCODColor::green, map)
{
    rng = TCODRandom::getInstance();
    type = getType();
}

Potion::~Potion()
{
    delete rng;
}

Potion_Type Potion::getType()
{
    int chance = rng->getInt(0, 100);

    if(chance > 60){
        return HEALING;
    }
    else if(chance < 60 && chance > 20){
        return POISON;
    }

    return DUD;
}

void Potion::use(Creature &drinker)
{
    switch(type){
        case HEALING:
            drinker.heal(5);
        case POISON:
            drinker.takeDamage(5);
        case DUD:
            break;
    }
}

