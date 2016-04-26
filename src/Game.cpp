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

Item* Game::findItem(const int &x, const int &y)
{
    if(items.empty()){
        return NULL;
    }
    ItemIter item = std::find_if(items.begin(), items.end(), [&](const Item *item){
            return item->x == x && item->y == y;
            });
    if(item != items.end()){
        return *item;
    }
    return NULL;
}
Monster* Game::findMonster(const int &x, const int &y)
{
    if(monsters.empty()){
        return NULL;
    }
    MonsterIter mon = std::find_if(monsters.begin(), monsters.end(), [&](const Monster *monster){
            return monster->x == x && monster->y == y;
            });
    if(mon != monsters.end()){
        return *mon;
    }
    return NULL;
}

ItemIter Game::removeItem(Item *item)
{
    return items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

MonsterIter Game::removeMonster(Monster *mon)
{
    return monsters.erase(std::remove(monsters.begin(), monsters.end(), mon), monsters.end());
}


void Game::update()
{
    gameState = IDLE;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS|TCOD_EVENT_MOUSE, &input, &mouse);
    player->update();
    if(gameState == NEW_TURN){
        for(MonsterIter iter = monsters.begin(); iter != monsters.end();){
            Monster *monster = *iter;
            if(monster->isInFov())
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
    for(ItemIter iter = items.begin(); iter != items.end(); iter++){
        Item *item = *iter;
        if(item->isInFov() && item->inPlay()){
            item->render();
        }
    }
    player->render();
    for(MonsterIter iter = monsters.begin(); iter != monsters.end(); iter++){
        Monster *monster = *iter;
        if(monster->isInFov()){
            monster->render();
        }
    }
}
