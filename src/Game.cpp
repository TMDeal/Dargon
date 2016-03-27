#include "Game.hpp"

Game::Game()
    :computeFov(true)
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "Dargon", false);
    rng = TCODRandom::getInstance();
    TCODSystem::setFps(60);
    map = new Map(80, 50);
    player = new Actor(40, 25, '@', TCODColor::white, map);
    actors.push(player);
    map->generate();
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
        Actor *creature = *iter;
        if(map->isInFov(creature->x, creature->y)){
            creature->render();
        }
    }
}

