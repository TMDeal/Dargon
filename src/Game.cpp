#include "Game.hpp"

Game::Game()
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(80, 50, "Dargon", false);
    player = new Actor(40, 25, '@', TCODColor::white);
    actors.push(player);
    map = new Map(80, 50);
}

Game::~Game()
{
    actors.clearAndDelete();
    delete map;
}

void Game::update()
{
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
    switch(key.vk){
        case TCODK_UP:
            if(!map->isWall(player->x, player->y-1)){
                player->y--;
            }
            break;
        case TCODK_DOWN:
            if(!map->isWall(player->x, player->y+1)){
                player->y++;
            }
            break;
        case TCODK_LEFT:
            if(!map->isWall(player->x-1, player->y)){
                player->x--;
            }
            break;
        case TCODK_RIGHT:
            if(!map->isWall(player->x+1, player->y)){
                player->x++;
            }
            break;
        default:
            break;
    }
}

void Game::render()
{
    TCODConsole::root->clear();
    map->render();
    
    for(Actor **iter = actors.begin(); iter != actors.end(); iter++){
        (*iter)->render();
    }
}
