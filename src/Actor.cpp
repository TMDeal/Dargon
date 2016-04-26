#include <sstream>

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
    int damage;
    damage = this->att;
    defender.defend(damage);
    if(damage != 0){
        game.gui->addLog(TCODColor::lightGrey, "%s attacks for %i damage", name.c_str(), damage);
    }
    else{
        game.gui->addLog(TCODColor::lightGrey, "%s fails to damage %s", name.c_str(), defender.name.c_str());
    }
}

void Actor::defend(int damage)
{
    takeDamage(damage);
}

void Actor::takeDamage(int damage)
{
    hp -= damage;
}

void Actor::heal(int healAmount)
{
    if(hp == max_hp){
        return;
    }
    hp += healAmount;
    if(hp > max_hp){
        hp = max_hp;
    }
}

std::string Actor::getInfo()
{
    std::stringstream streem;
    streem << name << " LVL: " << level;
    return streem.str();
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
