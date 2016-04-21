#include "Game.hpp"

Game::Game(int screenWidth, int screenHeight)
{
    gameState = STARTUP;
    gui = new Gui(screenWidth, screenHeight);
    TCODSystem::setFps(30);
    tiles = new Tile*[screenWidth];
    for(int i = 0; i < screenWidth; i++){
        tiles[i] = new Tile[screenHeight];
    }
    levelMap = new Map(screenWidth, screenHeight - Gui::PANEL_HEIGHT);
    player = new Player();
    levelMap->generate();
    player->computeFov();
}

Game::~Game()
{
    monsters.clear();
    items.clear();
}

void Game::update()
{
    gameState = IDLE;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS|TCOD_EVENT_MOUSE, &input, &mouse);
    player->update();
    if(gameState == NEW_TURN){
        for(MonsterIter iter = monsters.begin(); iter != monsters.end();){
            Monster *monster = *iter;
            monster->update();
            if(!monster->isAlive()){
                iter = monsters.erase(std::remove(
                            monsters.begin(), monsters.end(), monster), monsters.end());
            }
            else{
                iter++;
            }
        }
    }
}

void Game::render()
{
    gui->render();
    levelMap->render();
    player->render();
    for(MonsterIter iter = monsters.begin(); iter != monsters.end(); iter++){
        Monster *monster = *iter;
        if(monster->isInFov()){
            monster->render();
        }
    }
}
