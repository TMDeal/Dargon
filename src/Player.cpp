#include "Player.hpp"

Player::Player(int x, int y, Map *map)
    : super(x, y, '@', TCODColor::white, map)
{
    this->stats = new Stats(10, 10, 5, 5);
}

Player::~Player()
{
}

void Player::die()
{
    return;
}

void Player::update()
{
    super::update();
    if(stats->isAlive()){
        TCOD_key_t input;
        TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &input, NULL);
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

