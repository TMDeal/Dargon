#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Actor.hpp"
#include "Enums.hpp"
#include "Coordinates.hpp"

class Player : public Actor{
    public:
        Player();
        Player(int x, int y);
        ~Player();

        void init();
        void update();
        bool moveOrAttack(Direction dir);
        bool place(int x, int y);
        void getInput(TCOD_key_t input);
        void die();
    private:
        typedef Actor super;
        TCOD_key_t input;
        //need to create inventory for player
};

#endif /* PLAYER_HPP */
