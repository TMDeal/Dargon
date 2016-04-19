#include "Player.hpp"
#include "Game.hpp"

Player::Player(int x, int y)
    : super(x, y, '@', TCODColor::white)
{
    game.tiles[this->x][this->y].flag = HAS_PLAYER;
    init();
}

Player::Player()
    : super(0, 0, '@', TCODColor::white)
{
    game.tiles[this->x][this->y].flag = HAS_PLAYER;
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

bool Player::place(int x, int y){
    if(game.levelMap->canPlace(x, y)){
        game.tiles[x][y].flag = HAS_PLAYER;
        game.tiles[this->x][this->y].flag = SAFE;
        this->x = x;
        this->y = y;
        return true;
    }
    return false;
}


void Player::getInput(TCOD_key_t input){
    this->input = input;
}

void Player::update()
{
    bool moved = false;
    if(isAlive()){
        switch(input.vk){
            case TCODK_UP:
                if(move(UP)){
                    moved = true;
                    computeFov();
                }
                break;
            case TCODK_DOWN:
                if(move(DOWN)){
                    moved = true;
                    computeFov();
                }
                break;
            case TCODK_LEFT:
                if(move(LEFT)){
                    moved = true;
                    computeFov();
                }
                break;
            case TCODK_RIGHT:
                if(move(RIGHT)){
                    moved = true;
                    computeFov();
                }
                break;
            default:
                break;
        }
        if(moved){
            game.gameState = NEW_TURN;
        }
    }
    else{
        die();
    }
}

