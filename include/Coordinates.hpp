#ifndef COORDINATES_HPP
#define COORDINATES_HPP

typedef struct Coordinate{
    int x;
    int y;

    Coordinate(int newX, int newY) : x(newX), y(newY){}
    Coordinate() : x(0), y(0){}

    void set(int newX, int newY){
        x = newX;
        y = newY;
    }

    bool operator ==(const Coordinate &coor) const{
        return this->x == coor.x && this->y == coor.y;
    }

    bool operator !=(const Coordinate &coor) const{
        return !operator == (coor); 
    }

    bool operator <(const Coordinate &coor) const{
        return this->x < coor.x || (this->x == coor.x && this->y < coor.y);
    }

    bool operator >(const Coordinate &coor) const{
        return this->x > coor.x || (this->x == coor.x && this->y > coor.y);
    }

    const Coordinate &operator +=(const Coordinate &coor){
        this->x += coor.x;
        this->y += coor.y;
        return *this;
    }

    const Coordinate &operator -=(const Coordinate &coor){
        this->x -= coor.x;
        this->y -= coor.y;
        return *this;
    }

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