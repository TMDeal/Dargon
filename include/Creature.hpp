#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Actor.hpp"
#include "Map.hpp"
#include "Stats.hpp"

class Creature : public Actor{
    public:
        Creature(int x, int y, int ch, TCODColor col, Map *map);
        ~Creature();

        bool move(Direction dir);
        bool isAlive() const;
        void heal(int healAmount);
        void takeDamage(int damage);

        void attack(Creature &defender);
        int defend(Creature &attacker);

        virtual void update();
        virtual void die() = 0;
    private:
        typedef Actor super;
    protected:
        Stats *stats;  // Object to define Actor stats
};

#endif /* CREATURE_HPP */
