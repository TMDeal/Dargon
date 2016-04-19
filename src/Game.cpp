#include "Game.hpp"

Game::Game(int screenWidth, int screenHeight)
    :screenWidth(screenWidth), screenHeight(screenHeight)
{
    gameState = STARTUP;
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(screenWidth, screenHeight, "Dargon", false);
    TCODSystem::setFps(30);
    tiles = new Tile*[screenWidth];
    for(int i = 0; i < screenWidth; i++){
        tiles[i] = new Tile[screenHeight];
    }
    levelMap = new Map(screenWidth, screenHeight);
    player = new Player();
    levelMap->generate();
    player->computeFov();
}

Game::~Game()
{
}

template<class T>
typename vector<T>::iterator Game::findAtCoordinate(std::vector<T*> objs, const int &x, const int &y){
    return std::find_if(objs.begin(), objs.end(), [&](const T &obj){
            return obj.x == x && obj.y == y;
            });
}

template<class T>
typename vector<T>::iterator Game::remove(std::vector<T*> objs, T obj){
    return objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void Game::update()
{
    gameState = IDLE;
    TCOD_key_t input;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &input, NULL);
    player->getInput(input);
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
    TCODConsole::root->clear();
    levelMap->render();
    player->render();
    for(MonsterIter iter = monsters.begin(); iter != monsters.end(); iter++){
        Monster *monster = *iter;
        if(monster->isInFov()){
            monster->render();
        }
    }
}
