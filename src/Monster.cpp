#include "Monster.hpp"
#include "Game.hpp"
#include "PathCallBack.hpp"

Monster::Monster()
    :super(0, 0)
{
    game.tiles[this->x][this->y].flag = HAS_MONSTER;
    TCODRandom *rng = TCODRandom::getInstance();
    Monster_Type type = static_cast<Monster_Type>(rng->get(0, MAX_MON_TYPES-1));
    MonsterData data = monsterList[type];
    init(data);
}

Monster::Monster(int x, int y)
    :super(x, y)
{
    game.tiles[this->x][this->y].flag = HAS_MONSTER;
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

bool Monster::place(int x, int y){
    if(game.levelMap->canPlace(x, y)){
        game.tiles[x][y].flag = HAS_MONSTER;
        game.tiles[this->x][this->y].flag = SAFE;
        this->x = x;
        this->y = y;
        return true;
    }
    return false;
}

void Monster::update()
{
    if(this->isAlive()){
        if(this->isInFov()){
            game.levelMap->computePath(this->x, this->y, game.player->x, game.player->y);
            game.levelMap->walkPath(this->x, this->y);
            game.tiles[this->x][this->y].flag = HAS_MONSTER;
        }
    }
    else{
        die();
    }
}

void Monster::die()
{
    game.gui->addLog(TCODColor::lightGrey, "%s Died", name.c_str());
    game.tiles[this->x][this->y].flag = SAFE;
}
