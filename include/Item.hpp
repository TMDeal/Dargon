#ifndef ITEM_HPP
#define ITEM_HPP

#include "libtcod/libtcod.hpp"
#include "Enums.hpp"
#include "Monster.hpp"

class Item{
    public:
        Item(int x, int y, int ch, TCODColor col);
        virtual ~Item();

        virtual void use(Monster &Monster) = 0;
        bool inPlay() const;
        void update();
        void interact(Actor &actor);
    private:
        typedef Actor super;
    protected:
        bool hasBeenPicked;
        int ch;
        TCODColor col;
        Coordinate pos;
};

#endif /* ITEM_HPP */
