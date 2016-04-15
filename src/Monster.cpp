#include "Monster.hpp"
#include "Game.hpp"

Monster::Monster()
    :super(Coordinate(0, 0))
{
    TCODRandom *rng = TCODRandom::getInstance();
    Monster_Type type = static_cast<Monster_Type>(rng->get(0, MAX_MON_TYPES-1));
    MonsterData data = monsterList[type];
    init(data);
}

Monster::Monster(const Coordinate &pos)
    :super(pos)
{
    TCODRandom *rng = TCODRandom::getInstance();
    Monster_Type type = static_cast<Monster_Type>(rng->get(0, MAX_MON_TYPES-1));
    MonsterData data = monsterList[type];
    init(data);
}

Monster::~Monster()
{
}

void Monster::init(const MonsterData &monInfo){
    stats.max_hp  = monInfo.max_hp;
    stats.max_mp  = monInfo.max_mp;
    stats.hp      = monInfo.hp;
    stats.mp      = monInfo.mp;
    stats.attack  = monInfo.attack;
    stats.defense = monInfo.defense;
    stats.level   = monInfo.level;
    ch            = monInfo.ch;
    color         = monInfo.color;
}

void Monster::update()
{
    if(isAlive()){
        return;
    }
    else{
        die();
    }
}

void Monster::die()
{
    printf("Dargon Died\n");
    game.levelMap->removeActorOnTile(this->pos.x, this->pos.y);
}
