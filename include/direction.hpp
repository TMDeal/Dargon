#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <SDL2pp/Point.hh>

enum class Direction {
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    UP_LEFT,
};

const int MAX_DIRECTIONS = 8;

const SDL2pp::Point Directions[MAX_DIRECTIONS] = {
    {0, -1},  //UP
    {1, -1},  //UP-RIGHT
    {1, 0},   //RIGHT
    {1, 1},   //DOWN-RIGHT
    {0, 1},   //DOWN
    {-1, 1},  //DOWN-LEFT
    {-1, 0},  //LEFT
    {-1, -1}  //UP-LEFT
};

#endif /* DIRECTION_HPP */
