#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Actor.hpp"
#include "Item.hpp"
#include "Container.hpp"
#include "Coordinates.hpp"

class Player : public Actor{
    public:
        Player();
        Player(int x, int y);
        ~Player();

        void init();
        void update();
        bool moveOrAttack(Direction dir);
        void handleSpecialKey(int key);
        Item* useInventory();
        void pickup(Item *item);
        bool place(int newX, int newY);
        void displayStats() const;
        void die();
    private:
        typedef Actor super;
        Container *inventory;
        //need to create inventory for player
};

#endif /* PLAYER_HPP */
