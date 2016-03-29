#ifndef POTION_HPP
#define POTION_HPP

#include "Actor.hpp"

typedef enum Potion_Type{
    DUD,
    HEALING,
    POISON,
}Potion_Type;

class Potion : public Actor{
    public:
        Potion(int x, int y, int ch, TCODColor col, Map *map);
        ~Potion();

        Potion_Type getType();
        void drink(Actor &drinker);
    private:
        typedef Actor super;
        Potion_Type type;
        TCODRandom *rng;
};

#endif /* POTION_HPP */
