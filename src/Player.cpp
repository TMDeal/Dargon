#include "Player.hpp"
#include "Game.hpp"
#include "Monster.hpp"

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
    this->name   = "Rogue";
    this->max_hp = 10;
    this->max_mp = 10;
    this->hp     = max_hp;
    this->mp     = max_mp;
    this->att    = 5;
    this->def    = 5;
    this->level  = 1;
}

void Player::die()
{
    return;
}

bool Player::moveOrAttack(Direction dir)
{
    int newX = this->x + Directions[dir].x;
    int newY = this->y + Directions[dir].y;

    if(game.levelMap->canPlace(newX, newY)){
        game.gameState = NEW_TURN;
        game.tiles[newX][newY].flag = HAS_PLAYER;
        game.tiles[this->x][this->y].flag = SAFE;
        this->x = newX;
        this->y = newY;
        return true;
    }
    else if(game.tiles[newX][newY].flag == HAS_MONSTER){
        game.gameState = NEW_TURN;
        Monster &mon = game.find<Monster>(game.monsters, newX, newY);
        attack(mon);
    }
    return false;
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


void Player::update()
{
    if(isAlive()){
        switch(game.input.vk){
            case TCODK_UP:
                if(moveOrAttack(UP)){
                    computeFov();
                }
                break;
            case TCODK_DOWN:
                if(moveOrAttack(DOWN)){
                    computeFov();
                }
                break;
            case TCODK_LEFT:
                if(moveOrAttack(LEFT)){
                    computeFov();
                }
                break;
            case TCODK_RIGHT:
                if(moveOrAttack(RIGHT)){
                    computeFov();
                }
                break;
            case TCODK_CHAR:
                switch(game.input.c){
                    case 'h':
                        if(moveOrAttack(LEFT)){
                            computeFov();
                        }
                        break;
                    case 'j':
                        if(moveOrAttack(DOWN)){
                            computeFov();
                        }
                        break;
                    case 'k':
                        if(moveOrAttack(UP)){
                            computeFov();
                        }
                        break;
                    case 'l':
                        if(moveOrAttack(RIGHT)){
                            computeFov();
                        }
                        break;
                    case 'y':
                        if(moveOrAttack(UP_LEFT)){
                            computeFov();
                        }
                        break;
                    case 'u':
                        if(moveOrAttack(UP_RIGHT)){
                            computeFov();
                        }
                        break;
                    case 'b':
                        if(moveOrAttack(DOWN_LEFT)){
                            computeFov();
                        }
                        break;
                    case 'n':
                        if(moveOrAttack(DOWN_RIGHT)){
                            computeFov();
                        }
                        break;
                }
            default:
                break;
        }
    }
    else{
        die();
    }
}

