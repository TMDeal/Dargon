#include "Stats.hpp"

Stats::Stats()
    :hp(10), mp(10), attack(5), defense(0)
{
}

Stats::Stats(int hp, int mp, int attack, int defense, int level)
    :hp(hp), mp(mp), attack(attack), defense(defense), level(level)
{
}

Stats::~Stats()
{
}

bool Stats::isAlive() const
{
    return hp <= 0;
}

int Stats::getAttackRoll() const
{
    return attack;
}

int Stats::getDefenseRoll() const
{
    return defense;
}

void Stats::levelUp()
{
    hp += 1;
    mp += 1;
    attack += 1;
    defense += 1;
    level += 1;
}

void Stats::takeDamage(int damage)
{
    hp -= damage;
}

