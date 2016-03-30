#ifndef CREATUREFACTORY_HPP
#define CREATUREFACTORY_HPP

#include "Creature.hpp"
#include "Player.hpp"
#include "Dargon.hpp"

typedef enum Creature_Type{
    PLAYER,
    DARGON,
}Creature_Type;

class CreatureFactory{
    public:
        CreatureFactory(Map *map) :map(map){}
        Creature *makeCreature(Creature_Type type, int x, int y){
            switch(type){
                case PLAYER:
                    return new Player(x, y, map);
                    break;
                case DARGON:
                    return new Dargon(x, y, map);
                    break;
            }
        }
    private:
        Map *map;
};

#endif /* CREATUREFACTORY_HPP */
