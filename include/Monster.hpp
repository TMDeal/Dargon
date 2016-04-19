#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>
#include "Coordinates.hpp"
#include "Monster-data.hpp"
#include "Enums.hpp"
#include "Actor.hpp"

using std::string;

class Monster : public Actor{
    public:
        Monster();
        Monster(int x, int y);
        ~Monster();

        void init(const MonsterData &monInfo);
        bool place(int x, int y);
        void update();
        void die();
    private:
        typedef Actor super;
        string name;
};

#endif /* MONSTER_HPP */
