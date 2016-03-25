#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "libtcod/libtcod.hpp"

class Actor{
    public:
        int x, y; // X and Y positions of the actor

        Actor(int x, int y, int ch, const TCODColor col);
        void render() const;

    private:
        int ch;        // ascii character for Actor as an int
        TCODColor col; // the color of the Actor
};

#endif /* ACTOR_HPP */
