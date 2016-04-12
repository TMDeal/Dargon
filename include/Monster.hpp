#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>

#include "Actor.hpp"
#include "Map.hpp"
#include "Stats.hpp"

using std::string;

class Monster : public Actor{
    public:
        Monster(int x, int y, int ch, TCODColor col);
        ~Monster();

        void init(Stats monInfo);
        void update();
        void die();
    private:
        typedef Actor super;
        string name;
};

#endif /* MONSTER_HPP */
