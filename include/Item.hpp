#ifndef ITEM_HPP
#define ITEM_HPP

#include "libtcod/libtcod.hpp"
#include "Map.hpp"

class Item{
    public:
        Item(int x, int y, int ch, TCODColor col, Map *map);
        ~Item();

        void render();
    protected:
        int x, y;
        int ch;
        Map *map;
};

#endif /* ITEM_HPP */
