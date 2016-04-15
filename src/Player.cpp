#include "Player.hpp"
#include "Game.hpp"

Player::Player(const Coordinate &pos)
    : super(pos, '@', TCODColor::white)
{
    game.levelMap->setActorOnTile(*this, pos.x, pos.y);
    init();
}

Player::Player()
    : super(Coordinate(0, 0), '@', TCODColor::white)
{
    init();
}

Player::~Player()
{
}

void Player::init()
{
    stats.max_hp = 10;
    stats.max_mp = 10;
    stats.hp = stats.max_hp;
    stats.mp = stats.max_mp;
    stats.attack = 5;
    stats.defense = 5;
    stats.level = 1;
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
    if(isAlive()){
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
        die();
    }
}

