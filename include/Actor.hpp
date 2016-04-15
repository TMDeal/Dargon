#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "libtcod/libtcod.hpp"
#include "Enums.hpp"
#include "Coordinates.hpp"
#include "Stats.hpp"

class Actor{
    public:
        Actor();
        Actor(const Coordinate &pos);
        Actor(const Coordinate &pos, int ch, const TCODColor color);
        virtual ~Actor();

        bool place(int x, int y);
        bool move(Direction dir);
        void attack(Actor &defender);
        void defend(Actor &attacker);
        bool isAlive() const;

        bool collides(int x, int y);

        bool isInFov() const;
        void computeFov();

        void heal(int healAmount);
        void takeDamage(int damage);

        virtual void update() = 0;
        virtual void die() = 0;
        void render() const;

    protected:
        int ch;        // ascii character for Actor as an int
        TCODColor color; // the color of the Actor
        Coordinate pos;
        Stats stats;  // Object to define Actor stats
};

#endif /* ACTOR_HPP */
