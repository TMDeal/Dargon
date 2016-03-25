#include "Game.hpp"

Game::Game()
    :fovRadius(10), computeFov(true)
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "Dargon", false);
    TCODSystem::setFps(60);
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
            if(map->canWalk(player->x, player->y-1)){
                player->y--;
                computeFov = true;
            }
            break;
        case TCODK_DOWN:
            if(map->canWalk(player->x, player->y+1)){
                player->y++;
                computeFov = true;
            }
            break;
        case TCODK_LEFT:
            if(map->canWalk(player->x-1, player->y)){
                player->x--;
                computeFov = true;
            }
            break;
        case TCODK_RIGHT:
            if(map->canWalk(player->x+1, player->y)){
                player->x++;
                computeFov = true;
            }
            break;
        default:
            break;
    }

    if(computeFov){
        map->computeFov();
        computeFov = false;
    }
}

void Game::render()
{
    TCODConsole::root->clear();
    map->render();
    
    for(Actor **iter = actors.begin(); iter != actors.end(); iter++){
        Actor *actor = *iter;
        if(map->isInFov(actor->x, actor->y)){
            actor->render();
        }
    }
}

