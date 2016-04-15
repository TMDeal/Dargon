#include "Game.hpp"
#include <algorithm>

Game::Game(int screenWidth, int screenHeight)
    :screenWidth(screenWidth), screenHeight(screenHeight), gameState(STARTUP)
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(screenWidth, screenHeight, "Dargon", false);
    rng = TCODRandom::getInstance();
    TCODSystem::setFps(30);
    levelMap = new Map(screenWidth, screenHeight);
    player = new Player();
    levelMap->generate();
}

Game::~Game()
{
    enemies.clear();
}

void Game::placeActor(int x, int y, bool playerStart){
    if(playerStart){
        player->place(x, y);
    }
    int roomMonsters = rng->getInt(0, MAX_ROOM_MONSTERS);
    if(roomMonsters > 0){
        if(levelMap->canPlace(x, y)){
            enemies.push_back(new Monster(Coordinate(x, y)));
        }
        roomMonsters--;
    }
}

ActorsIter Game::removeActor(Actor *actor)
{
    return enemies.erase(std::remove(enemies.begin(), enemies.end(), actor), enemies.end());
}

void Game::createRoom(bool first, int x1, int y1, int x2, int y2)
{
    levelMap->dig(x1, y1, x2, y2);
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
        for(ActorsIter iter = enemies.begin(); iter != enemies.end();){
            Actor *actor = *iter;
            actor->update();
            if(!actor->isAlive()){
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
    levelMap->render();
    player->render();
    for(ActorsIter iter = enemies.begin(); iter != enemies.end(); iter++){
        Actor *actor = *iter;
        if(actor->isInFov()){
            actor->render();
        }
    }
}

