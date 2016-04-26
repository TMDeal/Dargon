#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

#include "libtcod/libtcod.hpp"
#include "Effect.hpp"

typedef enum Usable_Type{
    FOOD,
    POTION,
    SCROLL,
    MAX_USABLE_TYPES,
}Item_Type;

typedef enum Armor_Type{
    MAX_ARMOR_TYPE,
}Armor_Type;

typedef enum Weapon_Type{
    MAX_WEAPON_TYPE,
}Weapon_Type;

class Item{
    friend class Container;
    public:
        Item(int x, int y);
        Item();
        virtual ~Item();

        bool isInFov() const;

        bool pick();
        bool inPlay() const;
        virtual void use(Actor &actor) = 0;
        virtual void render() = 0;
    public:
        int x, y;
        std::string name;
    protected:
        bool beenPicked;
        int ch;
        TCODColor col;
        Effect *effect;
};

#endif /* ITEM_HPP */
