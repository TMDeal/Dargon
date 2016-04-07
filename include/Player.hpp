#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Creature.hpp"

class Player : public Creature{
    public:
        Player(int x, int y, Map *map);
        ~Player();

        void update();
        void getInput(TCOD_key_t input);
        void die();
    private:
        typedef Creature super;
        TCOD_key_t input;
        //need to create inventory for player
};

#endif /* PLAYER_HPP */
