#ifndef POTION_HPP
#define POTION_HPP

#include "Item.hpp"

typedef enum Potion_Type{
    DUD,
    HEALING,
    POISON,
}Potion_Type;

class Potion : public Item{
    public:
        Potion(int x, int y, Map *map);
        ~Potion();

        Potion_Type getType();
        void use(Creature &drinker);
    private:
        typedef Item super;
        Potion_Type type;
        TCODRandom *rng;
};

#endif /* POTION_HPP */
