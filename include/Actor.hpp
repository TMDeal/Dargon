#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "libtcod/libtcod.hpp"

class Actor{
    public:
        int x, y; // X and Y positions of the Actor

        Actor(int x, int y, int ch, const TCODColor col);
        void render() const;

    private:
        int ch;        // ascii character for Actor as an int
        TCODColor col; // the color of the Actor
};

#endif /* CREATURE_HPP */
