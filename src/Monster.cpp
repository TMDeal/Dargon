#include "Monster.hpp"
#include "Game.hpp"

Monster::Monster()
    :super(0, 0)
{
    game.tiles[x][y].flag.set(HAS_MONSTER);
    game.tiles[x][y].flag.reset(SAFE);
    TCODRandom *rng = TCODRandom::getInstance();
    type = static_cast<Monster_Type>(rng->get(0, MAX_MON_TYPES-1));
    MonsterData data = monsterList[type];
    init(data);
}

Monster::Monster(int x, int y)
    :super(x, y)
{
    game.tiles[x][y].flag.set(HAS_MONSTER);
    game.tiles[x][y].flag.reset(SAFE);
    TCODRandom *rng = TCODRandom::getInstance();
    Monster_Type type = static_cast<Monster_Type>(rng->get(0, MAX_MON_TYPES-1));
    MonsterData data = monsterList[type];
    init(data);
}

Monster::~Monster()
{
}

void Monster::init(const MonsterData &monInfo){
    this->name    = monInfo.name;
    this->max_hp  = monInfo.max_hp;
    this->max_mp  = monInfo.max_mp;
    this->hp      = monInfo.max_hp;
    this->mp      = monInfo.max_mp;
    this->att     = monInfo.attack;
    this->def     = monInfo.defense;
    this->level   = monInfo.level;
    this->ch      = monInfo.ch;
    this->color   = monInfo.color;
}

bool Monster::place(int newX, int newY){
    if(game.levelMap->canPlace(newX, newY)){
        game.tiles[newX][newY].flag.set(HAS_MONSTER);
        game.tiles[newX][newY].flag.reset(SAFE);
        game.tiles[x][y].flag.set(SAFE);
        game.tiles[x][y].flag.reset(HAS_MONSTER);
        x = newX;
        y = newY;
        return true;
    }
    return false;
}

void Monster::update()
{
    if(this->isAlive()){
        if(this->isInFov()){
            game.levelMap->computePath(x, y, game.player->x, game.player->y);
            int newX, newY;
            if(game.levelMap->walkPath(newX, newY)){
                if(game.tiles[newX][newY].flag.test(HAS_PLAYER)){
                    return;
                }
                else{
                    game.tiles[x][y].flag.reset(HAS_MONSTER);
                    game.tiles[x][y].flag.set(SAFE);
                    x = newX;
                    y = newY;
                    game.tiles[x][y].flag.set(HAS_MONSTER);
                    game.tiles[x][y].flag.reset(SAFE);
                }
            }
        }
    }
    else{
        die();
    }
}

void Monster::die()
{
    game.gui->addLog(TCODColor::lightGrey, "%s Died", name.c_str());
    game.tiles[x][y].flag.reset(HAS_MONSTER);
    game.tiles[x][y].flag.set(SAFE);
}
