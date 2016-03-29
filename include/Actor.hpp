#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "libtcod/libtcod.hpp"
#include "Map.hpp"
#include "Stats.hpp"

class Actor{
    public:
        Actor(int x, int y, int ch, const TCODColor col, Map *map);

        bool move(Direction dir);
        bool move(int x, int y);
        bool collides(int x, int y);
        bool isAlive() const;
        void heal(int healAmount);
        void takeDamage(int damage);

        bool isInFov() const;
        void computeFov();

        void update();
        void render() const;

    private:
        int x, y; // X and Y positions of the Actor
        int ch;        // ascii character for Actor as an int
        Stats *stats;  // Object to define Actor stats
        Map *map;      // Map for the Actor to reference
        TCODColor col; // the color of the Actor
};

#endif /* CREATURE_HPP */
