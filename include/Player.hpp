#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Actor.hpp"
#include "Coordinates.hpp"

class Player : public Actor{
    public:
        Player();
        Player(const Coordinate &pos);
        ~Player();

        void init();
        void update();
        void getInput(TCOD_key_t input);
        void die();
    private:
        typedef Actor super;
        TCOD_key_t input;
        //need to create inventory for player
};

#endif /* PLAYER_HPP */
