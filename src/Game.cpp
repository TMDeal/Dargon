#include "Game.hpp"

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
    actors.clearAndDelete();
    delete map;
}

void Game::placeActor(int x, int y, bool playerStart){
    if(playerStart){
        player->place(x, y);
    }
    int roomMonsters = rng->getInt(0, MAX_ROOM_MONSTERS);
    if(roomMonsters > 0){
        if(map->canWalk(x, y)){
            actors.push(creatureFactory->makeDargon(x, y));
        }
        roomMonsters--;
    }
}

void Game::removeActor(Actor *actor)
{
    if(actors.contains(actor)){
        actors.remove(actor);
    }
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
    player->update();
    gameState = NEW_TURN;
    if(gameState == NEW_TURN){
        for(Actor **iter = actors.begin(); iter != actors.end(); iter++){
            Actor *actor = *iter;
            if(!actor->inPlay()){
                actor->update();
                removeActor(actor); 
            }
            else{
                actor->update();
            }
        }
    }
}

void Game::render()
{
    TCODConsole::root->clear();
    map->render();
    player->render();
    for(Actor **iter = actors.begin(); iter != actors.end(); iter++){
        Actor *actor = *iter;
        if(actor->isInFov()){
            actor->render();
        }
    }
}

