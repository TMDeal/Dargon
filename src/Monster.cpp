#include "Monster.hpp"
#include "Game.hpp"

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
            printf("I SEE YOU\n");
            int dx = game.player->x - this->x;
            int dy = game.player->y - this->y;
            float distance = sqrtf(dx*dx + dy*dy);
            if(distance >= 2){
                printf("I CHASE YOU\n");
                dx = (int)(round(dx/distance)) + this->x;
                dy = (int)(round(dy/distance)) + this->y;
                if(game.levelMap->canPlace(dx, dy)){
                    printf("I MOVE TO YOU\n");
                    game.tiles[this->x][this->y].flag = SAFE;
                    this->x = dx;
                    this->y = dy;
                    game.tiles[dx][dy].flag = HAS_MONSTER;
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
    printf("Dargon Died\n");
    game.tiles[this->x][this->y].flag = SAFE;
}
