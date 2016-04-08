#include "Game.hpp"
#include <algorithm>

Game::Game(int screenWidth, int screenHeight)
    :screenWidth(screenWidth), screenHeight(screenHeight), gameState(STARTUP)
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(screenWidth, screenHeight, "Dargon", false);
    rng = TCODRandom::getInstance();
    TCODSystem::setFps(30);
    map = new Map(80, 50);
    creatureFactory = new CreatureFactory(map);
    player = creatureFactory->makePlayer();
    map->generate();
}

Game::~Game()
{
    actors.clear();
}

void Game::placeActor(int x, int y, bool playerStart){
    if(playerStart){
        player->place(x, y);
    }
    int roomMonsters = rng->getInt(0, MAX_ROOM_MONSTERS);
    if(roomMonsters > 0){
        if(map->canWalk(x, y)){
            actors.push_back(creatureFactory->makeDargon(x, y));
        }
        roomMonsters--;
    }
}

ActorsIter Game::removeActor(Actor *actor)
{
    return actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end());
}

void Game::createRoom(bool first, int x1, int y1, int x2, int y2)
{
    map->dig(x1, y1, x2, y2);
    int x;
    int y;
    if(first){
       x = (x1 + x2) / 2;
       y = (y1 + y2) / 2;
       placeActor(x, y, first);
    }
    else{
        x = rng->getInt(x1, x2);
        y = rng->getInt(y1, y2);
        placeActor(x, y);
    }
}

void Game::update()
{
    if(gameState == STARTUP){
        player->computeFov();
    }
    gameState = IDLE;
    TCOD_key_t input;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &input, NULL);
    player->getInput(input);
    player->update();
    gameState = NEW_TURN;
    if(gameState == NEW_TURN){
        for(ActorsIter iter = actors.begin(); iter != actors.end();){
            Actor *actor = *iter;
            actor->update();
            if(!actor->inPlay()){
                iter = removeActor(actor); 
            }else{
                iter++;
            }
        }
    }
}

void Game::render()
{
    TCODConsole::root->clear();
    map->render();
    player->render();
    for(ActorsIter iter = actors.begin(); iter != actors.end(); iter++){
        Actor *actor = *iter;
        if(actor->isInFov()){
            actor->render();
        }
    }
}

