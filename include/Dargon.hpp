#ifndef DARGON_HPP
#define DARGON_HPP

#include <cstdio>
#include "Creature.hpp"
#include "Map.hpp"

class Dargon : public Creature{
    public:
        Dargon(int x, int y, Map *map);
        ~Dargon();

        void update();
        void die();
    private:
        typedef Creature super;
};

#endif /* DARGON_HPP */
