#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "Actor.hpp"

typedef enum Effect_Type{
    DUD,
    HEALING,
    POISON,
    MAX_EFFECT_TYPES,
}Effect_Type;

class Effect{
    public:
        virtual void deliver(Actor &actor) = 0;
        virtual bool canDeliver() = 0;
};

class Heal : public Effect{
    public:
        static Heal& getInstance();
        void deliver(Actor &actor);
        bool canDeliver();
    private:
        Heal();
};

class Poison : public Effect{
    public:
        static Poison& getInstance();
        void deliver(Actor &actor);
        bool canDeliver();
    private:
        Poison();
};

class Dud : public Effect{
    public:
        static Dud& getInstance();
        void deliver(Actor &actor);
        bool canDeliver();
    private:
        Dud();
};

static Effect* effectList[MAX_EFFECT_TYPES] = {
    &Dud::getInstance(),
    &Heal::getInstance(),
    &Poison::getInstance(),
};


#endif /* EFFECT_HPP */
