#ifndef POTION_HPP
#define POTION_HPP

#include "Item.hpp"

class Potion : public Item{
    public:
        Potion(int x, int y);
        ~Potion();

        Potion_Type getType();
        void use(Monster &drinker);
    private:
        typedef Item super;
        Potion_Type type;
        TCODRandom *rng;
};

#endif /* POTION_HPP */
