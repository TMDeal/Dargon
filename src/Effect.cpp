#include "Effect.hpp"
#include "Game.hpp"

Poison::Poison()
{
}

Poison& Poison::getInstance()
{
    static Poison instance;
    return instance;
}

bool Poison::canDeliver()
{
    return true;
}

void Poison::deliver(Actor &actor)
{
    actor.takeDamage(5);
}

Heal::Heal()
{
}

Heal& Heal::getInstance()
{
    static Heal instance;
    return instance;
}


bool Heal::canDeliver()
{
    return true;
}

void Heal::deliver(Actor &actor)
{
    actor.heal(5);
}

Dud::Dud()
{
}

Dud& Dud::getInstance()
{
    static Dud instance;
    return instance;
}

bool Dud::canDeliver()
{
	return true;
}

void Dud::deliver(Actor &actor)
{
    game.gui->addLog(TCODColor::lightGrey, "You feel nothing...");
}

