#include "Monster.hpp"

Monster::Monster(int x, int y, int ch, TCODColor col)
    : super(x, y, ch, col), name("")
{
}

Monster::~Monster()
{
}

void Monster::init(Stats monInfo){
    stats.max_hp = monInfo.max_hp;
    stats.max_mp = monInfo.max_mp;
    stats.attack = monInfo.attack;
    stats.defense = monInfo.defense;
    stats.level = monInfo.level;
}

void Monster::update()
{
    if(!isAlive()){
        die();
    }
}

void Monster::die()
{
    printf("Dargon Died\n");
    actorMap->removeActorOnTile(this->pos.x, this->pos.y);
}
