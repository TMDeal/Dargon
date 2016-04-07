#include "Player.hpp"

Player::Player(int x, int y, Map *map)
    : super(x, y, '@', TCODColor::white, map)
{
    this->stats = new Stats(10, 10, 5, 5);
    map->setActorOnTile(*this, x, y);
}

Player::~Player()
{
}

void Player::die()
{
    return;
}

void Player::getInput(TCOD_key_t input){
    this->input = input;
}

void Player::update()
{
    super::update();
    if(stats->isAlive()){
        switch(input.vk){
            case TCODK_UP:
                if(move(UP)){
                    computeFov();
                }
                break;
            case TCODK_DOWN:
                if(move(DOWN)){
                    computeFov();
                }
                break;
            case TCODK_LEFT:
                if(move(LEFT)){
                    computeFov();
                }
                break;
            case TCODK_RIGHT:
                if(move(RIGHT)){
                    computeFov();
                }
                break;
            default:
                break;
        }
    }
    else{
        return;
    }
}

