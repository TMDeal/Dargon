#ifndef ENUMS_HPP
#define ENUMS_HPP

typedef enum Game_State{
    STARTUP,
    IDLE,
    NEW_TURN,
    VICTORY,
    DEFEAT,
}Game_State;

typedef enum Item_Type{
    MISCELLANEOUS,
    FOOD,
    POTION,
    SCROLL,
    GOLD,
    WEAPON,
    ARMOR,
}Item_Type;

typedef enum Potion_Type{
    DUD,
    HEALING,
    POISON,
}Potion_Type;

typedef enum Monster_Type{
    DARGON,
}Monster_Type;

typedef enum Direction{
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    UP_LEFT,
    STAY,
}Direction;

#endif /* ENUMS_HPP */
