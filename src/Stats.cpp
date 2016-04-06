#include "Stats.hpp"

Stats::Stats(int maxHp, int maxMp, int attack, int defense, int level)
    :maxHp(maxHp), maxMp(maxMp), attack(attack), defense(defense), level(level)
{
    hp = maxHp;
    mp = maxMp;
}

Stats::~Stats()
{
}

bool Stats::isAlive() const
{
    return hp >= 0;
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

void Stats::heal(int healAmount)
{
    if(hp <= maxHp || hp + healAmount <= maxHp){
        hp += healAmount;
    }
}

void Stats::displayeStats() const
{
    printf("Health: %i/%i\n", this->maxHp, this->hp);
}

