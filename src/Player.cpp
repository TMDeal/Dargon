#include "Player.hpp"
#include "Game.hpp"
#include "Usable.hpp"
#include "Monster.hpp"

Player::Player(int x, int y)
    : super(x, y, '@', TCODColor::white)
{
    game.tiles[x][y].flag.set(HAS_PLAYER);
    this->inventory = new Container();
    // inventory->add(new Usable());
    init();
}

Player::Player()
    : super(0, 0, '@', TCODColor::white)
{
    game.tiles[x][y].flag.set(HAS_PLAYER);
    this->inventory = new Container();
    // inventory->add(new Usable());
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
    int newX = x + Directions[dir].x;
    int newY = y + Directions[dir].y;

    if(game.levelMap->canPlace(newX, newY)){
        game.gameState = NEW_TURN;
        game.tiles[newX][newY].flag.set(HAS_PLAYER);
        game.tiles[x][y].flag.reset(HAS_PLAYER);
        x = newX;
        y = newY;
        return true;
    }
    else if(game.tiles[newX][newY].flag.test(HAS_MONSTER)){
        game.gameState = NEW_TURN;
        Monster *mon = game.findMonster(newX, newY);
        attack(*mon);
    }
    return false;
}

void Player::displayStats() const
{
    game.gui->renderBar(0, 1, "HP", this->hp, this->max_hp,
            TCODColor::lightRed, TCODColor::darkerRed);
    game.gui->renderBar(0, 2, "MP", this->mp, this->max_mp,
            TCODColor::lightBlue, TCODColor::darkerBlue);
}

Item* Player::useInventory()
{
    game.gui->renderContainerMenu(*inventory);
    TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &game.input, NULL, true);

    if(game.input.vk == TCODK_CHAR){
        int index = game.input.c - 'a';
        if(index >= 0 && index < inventory->size()){
            return inventory->at(index);
        }
    }
    else{
        return NULL;
    }
}

bool Player::place(int newX, int newY){
    if(game.levelMap->canPlace(newX, newY)){
        game.tiles[newX][newY].flag.set(HAS_PLAYER);
        game.tiles[x][y].flag.reset(HAS_PLAYER);
        x = newX;
        y = newY;
        return true;
    }
    return false;
}

void Player::handleSpecialKey(int key)
{
    switch(key){
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
        case 'i':
            {
                Item *item = useInventory();
                if(item){
                    item->use(*this);
                    inventory->remove(item);
                    game.gameState = NEW_TURN;
                }
                break;
            }
        case 'g':
            {
                // Item *item = game.find<Item>(game.items, x, y);
                game.gameState = NEW_TURN;
                Item *item = game.findItem(this->x, this->y);
                pickup(item);
            }
            break;
    }
}

void Player::pickup(Item *item)
{
    bool notOnItem = true;
    if(item){
        notOnItem = false;
        game.gui->addLog(TCODColor::lightGrey, "Picked up %s", item->name.c_str());
        inventory->add(item);
        item->pick();
    }
    else if(inventory->full()){
        game.gui->addLog(TCODColor::red, "Inventory is Full");
        return;
    }
    if(notOnItem){
        game.gui->addLog(TCODColor::lightGrey, "Nothing to pick up here");
    }
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
                handleSpecialKey(game.input.c);
            default:
                break;
        }
    }
    else{
        die();
    }
}

