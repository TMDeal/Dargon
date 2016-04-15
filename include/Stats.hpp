#ifndef STATS_HPP
#define STATS_HPP

#include <cstdio>

struct Stats{
    int max_hp;
    int max_mp;
    int hp;
    int mp;
    int attack;
    int defense;
    int level;

    Stats() : max_hp(1), max_mp(1), hp(max_hp), mp(max_mp), attack(1), defense(1), level(1){};

    Stats(int max_hp, int max_mp, int attack, int defense, int level)
        : max_hp(max_hp), max_mp(max_mp), hp(max_hp),
        mp(max_mp), attack(attack), defense(defense), level(level){};

    void displayStats(){
        printf("LEVEL: %i\n HP: %i/%i\n MP: %i/%i\n ATT: %i\n DEF: %i\n",
                level, max_hp, hp, max_mp, mp, attack, defense);
    }
};

#endif /* STATS_HPP */
