#ifndef COORDINATES_HPP
#define COORDINATES_HPP

typedef struct Coordinate{
    int x;
    int y;
}Coordinate;

const struct Coordinate Directions[9]={
    {0, -1},  //UP
    {1, -1},  //UP-RIGHT
    {1, 0},   //RIGHT
    {1, 1},   //DOWN-RIGHT
    {0, 1},   //DOWN
    {-1, 1},  //DOWN-LEFT
    {-1, 0},  //LEFT
    {-1, -1}, //UP-LEFT
    {0, 0}    //STAY
};

#endif /* COORDINATES_HPP */
