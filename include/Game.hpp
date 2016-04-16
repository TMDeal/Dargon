#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "libtcod/libtcod.hpp"
#include "templates_out/projectPaths.h"
#include "Enums.hpp"
#include "Actor.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include "Map.hpp"

typedef std::vector<Monster*>::iterator MonsterIter;
typedef std::vector<Item*>::iterator ItemIter;

typedef struct Environment{
    std::vector<Monster*> monsters;
    std::vector<Item*> items;
    TCODRandom *rng;
    Game_State gameState;
    Map *levelMap;
}Environment;

#define gameState env.gameState

extern Environment env;

namespace Game{
    static void init(int screenWidth, int screenHeight)
    {
        gameState = STARTUP;
        TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
        TCODConsole::initRoot(screenWidth, screenHeight, "Dargon", false);
        TCODSystem::setFps(30);
        env.levelMap = new Map(screenWidth, screenHeight);
        env.levelMap->generate();
        you->computeFov();
    }

    static void update()
    {
        gameState = IDLE;
        TCOD_key_t input;
        TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &input, NULL);
        you->getInput(input);
        you->update();
        gameState = NEW_TURN;
        if(gameState == NEW_TURN){
            for(MonsterIter iter = env.monsters.begin(); iter != env.monsters.end();){
                Monster *monster = *iter;
                monster->update();
                if(!monster->isAlive()){
                    iter = env.monsters.erase(std::remove(
                                env.monsters.begin(), env.monsters.end(), monster), env.monsters.end());
                }
                else{
                    iter++;
                }
            }
        }
    }

    static void render()
    {
        TCODConsole::root->clear();
        env.levelMap->render();
        you->render();
        for(MonsterIter iter = env.monsters.begin(); iter != env.monsters.end(); iter++){
            Monster *monster = *iter;
            if(monster->isInFov()){
                monster->render();
            }
        }
    }
}

#endif /* GAME_HPP */
