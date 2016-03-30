#include "Player.hpp"

Player::Player(int x, int y, Map *map)
    : super(x, y, '@', TCODColor::white, map)
{
    this->stats = new Stats(10, 10, 5, 5);
}

Player::~Player()
{
}

