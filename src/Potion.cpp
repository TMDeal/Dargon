#include "Potion.hpp"

Potion::Potion(int x, int y, int ch, TCODColor col, Map *map)
    :super(x, y, ch, col, map)
{
    rng = TCODRandom::getInstance();
    type = randomType();
}

Potion_Type Potion::randomType()
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

void Potion::drink(Actor &drinker)
{
}

Potion::~Potion()
{
}

