#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Coordinates.hpp"
#include "Monster-data.hpp"
#include "Actor.hpp"

using std::string;

class Monster : public Actor{
    public:
        Monster();
        Monster(int x, int y);
        ~Monster();

        void init(const MonsterData &monInfo);
        bool place(int newX, int newY);
        void update();
        void die();
    private:
        typedef Actor super;
        Monster_Type type;
};

#endif /* MONSTER_HPP */
