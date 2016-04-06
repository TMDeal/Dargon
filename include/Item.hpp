#ifndef ITEM_HPP
#define ITEM_HPP

#include "libtcod/libtcod.hpp"
#include "Actor.hpp"
#include "Creature.hpp"
#include "Map.hpp"

class Item : public Actor{
    public:
        Item(int x, int y, int ch, TCODColor col, Map *map);
        virtual ~Item();

        virtual void use(Creature &creature) = 0;
        void update();
        void interact(Actor &actor);
    private:
        typedef Actor super;
};

#endif /* ITEM_HPP */
