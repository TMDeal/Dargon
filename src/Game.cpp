#include "Game.hpp"

Game::Game()
    :computeFov(true)
{
    TCODConsole::setCustomFont((getResPath() + "terminal.png").c_str());
    TCODConsole::initRoot(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "Dargon", false);
    rng = TCODRandom::getInstance();
    TCODSystem::setFps(30);
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

void Game::placeActor(int x, int y, bool playerStart){
    int roomMonsters = rng->getInt(0, MAX_ROOM_MONSTERS);
    if(playerStart){
        player->move(x, y);
    }
    if(roomMonsters > 0){
        if(map->canWalk(x, y)){
            actors.push(new Actor(x, y, '@', TCODColor::yellow, map));
        }
        roomMonsters--;
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
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
    switch(key.vk){
        case TCODK_UP:
            if(player->move(UP)){
                computeFov = true;
            }
            break;
        case TCODK_DOWN:
            if(player->move(DOWN)){
                computeFov = true;
            }
            break;
        case TCODK_LEFT:
            if(player->move(LEFT)){
                computeFov = true;
            }
            break;
        case TCODK_RIGHT:
            if(player->move(RIGHT)){
                computeFov = true;
            }
            break;
        default:
            break;
    }

    if(computeFov){
        player->computeFov();
        computeFov = false;
    }
}

void Game::render()
{
    TCODConsole::root->clear();
    map->render();

    for(Actor **iter = actors.begin(); iter != actors.end(); iter++){
        Actor *actor = *iter;
        if(actor->isInFov()){
            actor->render();
        }
    }
}

