#include "Actor.hpp"
#include "Game.hpp"

Actor::Actor(int x, int y, int ch, const TCODColor color)
    : x(x), y(y), ch(ch), color(color)
{
}

Actor::Actor(int x, int y)
    : x(x), y(y), ch('@'), color(TCODColor::black)
{
}

Actor::Actor()
    : x(0), y(0), ch('@'), color(TCODColor::black)
{
}

bool Actor::isAlive() const
{
    return hp > 0;
}

void Actor::attack(Actor &defender)
{
    defender.takeDamage(this->att);
}

void Actor::defend(Actor &attacker)
{
}

void Actor::heal(int healAmount)
{
    this->hp += healAmount;
}

void Actor::takeDamage(int damage)
{
    this->hp -= damage;
}

Actor::~Actor()
{
}

bool Actor::isInFov() const{
    return game.levelMap->isInFov(this->x, this->y);
}

bool Actor::collides(int x, int y){
    return this->x == x && this->y == y;
}

void Actor::computeFov()
{
    game.levelMap->computeFov(this->x, this->y);
}

void Actor::render() const {
    TCODConsole::root->setChar(this->x, this->y, ch);
    TCODConsole::root->setCharForeground(this->x, this->y, color);
}
