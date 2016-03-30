#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "libtcod/libtcod.hpp"
#include "Map.hpp"

class Map;
class Actor{
    public:
        Actor(int x, int y, int ch, const TCODColor col, Map *map);

        bool place(int x, int y);
        bool collides(int x, int y);

        bool isInFov() const;
        void computeFov();

        virtual void update() = 0;
        void render() const;

    protected:
        int x, y;      // X and Y positions of the Actor
        int ch;        // ascii character for Actor as an int
        Map *map;      // Map for the Actor to reference
        TCODColor col; // the color of the Actor
};

#endif /* ACTOR_HPP */
