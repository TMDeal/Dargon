#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Creature.hpp"

class Player : public Creature{
    public:
        Player(int x, int y, Map *map);
        ~Player();
    private:
        typedef Creature super;
        //need to create inventory for player
};

#endif /* PLAYER_HPP */
