#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <string>

#include "libtcod/libtcod.hpp"
#include "Enums.hpp"
#include "Coordinates.hpp"

class Actor{
    public:
        Actor();
        Actor(int x, int y);
        Actor(int x, int y, int ch, const TCODColor color);
        virtual ~Actor();

        virtual bool place(int x, int y) = 0;
        void attack(Actor &defender);
        void defend(Actor &attacker);
        bool isAlive() const;

        std::string getInfo();
        bool collides(int x, int y);

        bool isInFov() const;
        void computeFov();

        void heal(int healAmount);
        void takeDamage(int damage);

        virtual void update() = 0;
        virtual void die() = 0;
        void render() const;

    public:
        int x, y;
    protected:
        std::string name;
        int ch;        // ascii character for Actor as an int
        int max_hp, hp;
        int max_mp, mp;
        int att;
        int def;
        int level;
        TCODColor color; // the color of the Actor
};

#endif /* ACTOR_HPP */
