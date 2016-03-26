#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "libtcod/libtcod.hpp"

class Creature{
    public:
        int x, y; // X and Y positions of the actor

        Creature(int x, int y, int ch, const TCODColor col);
        void render() const;

    private:
        int ch;        // ascii character for Creature as an int
        TCODColor col; // the color of the Creature
};

#endif /* CREATURE_HPP */
