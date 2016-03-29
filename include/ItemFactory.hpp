#ifndef ITEMFACTORY_HPP
#define ITEMFACTORY_HPP

#include "libtcod/libtcod.hpp"
#include "Actor.hpp"
#include "Potion.hpp"

typedef enum Item_Type{
    MISCELLANEOUS = '{',
    FOOD = '%',
    POTION = '!',
    SCROLL = '?',
    GOLD = '$',
    WEAPON = ')',
    ARMOR = '[',
}Item_Type;

class ItemFactory{
    public:
        ItemFactory(Map *map) :map(map) {}
        Actor *makeItem(Item_Type type, int x, int y){
            switch(type){
                case MISCELLANEOUS:
                    break;
                case FOOD:
                    break;
                case POTION:
                    return new Potion(x, y, POTION, TCODColor::green, map);
                case SCROLL:
                    break;
                case GOLD:
                    break;
                case WEAPON:
                    break;
                case ARMOR:
                    break;
            }
            return NULL;
        }
    private:
        Map *map;
};

#endif /* ITEMFACTORY_HPP */
