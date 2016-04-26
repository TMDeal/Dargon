#include "Usable.hpp"
#include "Game.hpp"

Usable::Usable(int x, int y)
    : super(x, y)
{
    rng = TCODRandom::getInstance();
    usableType = static_cast<Usable_Type>(rng->getInt(0, MAX_USABLE_TYPES-1));
    effectType = static_cast<Effect_Type>(rng->getInt(0, MAX_EFFECT_TYPES-1));
    init();
}

Usable::Usable()
    : super(0, 0)
{
    rng = TCODRandom::getInstance();
    usableType = static_cast<Usable_Type>(rng->getInt(0, MAX_USABLE_TYPES-1));
    effectType = static_cast<Effect_Type>(rng->getInt(0, MAX_EFFECT_TYPES-1));
    init();
}

void Usable::init()
{
    effect = effectList[effectType];
    getName(usableType);
    switch(usableType){
        case POTION:
            this->ch = '!';
            this->col = TCODColor::darkGreen;
            break;
        case FOOD:
            this->ch = '%';
            this->col = TCODColor::darkRed;
            break;
        case SCROLL:
            this->ch = '?';
            this->col = TCODColor::blue;
            break;
    }
}

void Usable::getName(Usable_Type type)
{
    switch(type){
        case POTION:
            name += "Potion ";
            break;
        case FOOD:
            name += "Ration ";
            break;
        case SCROLL:
            name += "Scroll ";
            break;
    }
    name += effect_describers[effectType];
}

void Usable::render()
{
    TCODConsole::root->setChar(this->x, this->y, ch);
    TCODConsole::root->setCharForeground(this->x, this->y, col);
}

void Usable::use(Actor &actor)
{
    effect->deliver(actor);
    game.gui->addLog(TCODColor::lightGrey, "used %s", name.c_str());
}

Usable::~Usable()
{
}

