#include "Actor.hpp"
#include "Game.hpp"

Actor::Actor(const Coordinate &pos, int ch, const TCODColor color)
    : pos(pos), ch(ch), color(color)
{
    game.levelMap->setActorOnTile(*this, this->pos.x, this->pos.y);
}

Actor::Actor(const Coordinate &pos)
    :pos(pos), ch('@'), color(TCODColor::black)
{
    game.levelMap->setActorOnTile(*this, this->pos.x, this->pos.y);
}

Actor::Actor()
    : ch('@'), color(TCODColor::black)
{
    pos.set(0, 0);
    game.levelMap->setActorOnTile(*this, this->pos.x, this->pos.y);
}

bool Actor::isAlive() const
{
    return stats.hp > 0;
}

void Actor::attack(Actor &defender)
{
    defender.takeDamage(stats.attack);
}

void Actor::defend(Actor &attacker)
{
}

void Actor::heal(int healAmount)
{
    stats.hp += healAmount;
}

void Actor::takeDamage(int damage)
{
    stats.hp -= damage;
}

Actor::~Actor()
{
}

bool Actor::move(Direction dir)
{
    int newX = this->pos.x + Directions[dir].x;
    int newY = this->pos.y + Directions[dir].y;

    if(game.levelMap->canPlace(newX, newY)){
        game.levelMap->setActorOnTile(*this, newX, newY);
        game.levelMap->removeActorOnTile(this->pos.x, this->pos.y);
        pos.set(newX, newY);
        return true;
    }
    else if(game.levelMap->isActorOnTile(newX, newY)){
        attack(*game.levelMap->getActorOnTile(newX, newY));
    }
    return false;
}

bool Actor::isInFov() const{
    return game.levelMap->isInFov(this->pos.x, this->pos.y);
}

bool Actor::collides(int x, int y){
    return this->pos.x == x && this->pos.y == y;
}

void Actor::computeFov()
{
    game.levelMap->computeFov(this->pos.x, this->pos.y);
}

bool Actor::place(int x, int y){
    if(game.levelMap->canPlace(x, y)){
        game.levelMap->setActorOnTile(*this, x, y);
        game.levelMap->removeActorOnTile(this->pos.x, this->pos.y);
        pos.set(x, y);
        return true;
    }
    return false;
}

void Actor::render() const {
    TCODConsole::root->setChar(pos.x, pos.y, ch);
    TCODConsole::root->setCharForeground(pos.x, pos.y, color);
}
