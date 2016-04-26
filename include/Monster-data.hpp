#ifndef MONSTER_DATA_HPP
#define MONSTER_DATA_HPP

#include <cstdio>

#include "libtcod/libtcod.hpp"
#include "libtcod/color.hpp"
#include "Coordinates.hpp"

typedef struct MonsterData{
    const char *name;
    TCOD_color_t color;
    int ch;

    int max_hp, max_mp;
    int attack, defense;
    int level;
}MonsterData;

typedef enum Monster_Type{
    DARGON,
    MAX_MON_TYPES,
}Monster_Type;

const static MonsterData monsterList[] = {
    {"Dargon", {0, 0, 255}, 'D', 10, 10, 5, 5, 1},
};

#endif /* MONSTER_DATA_HPP */
