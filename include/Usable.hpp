#ifndef USABLE_HPP
#define USABLE_HPP

#include "string"

#include "Item.hpp"
#include "Effect.hpp"
#include "Actor.hpp"

static const std::string effect_describers[] = {
    "of Uselessness",
    "of Healing",
    "of Poison",
};

class Usable : public Item{
    public:
        Usable(int x, int y);
        Usable();
        ~Usable();

        void init();
        void use(Actor &actor);
        void render();
    private:
        void setEffect();
        void getName(Usable_Type type);
    private:
        typedef Item super;
        TCODRandom *rng;
        Usable_Type usableType;
        Effect_Type effectType;
};

#endif /* USABLE_HPP */
