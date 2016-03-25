#include "libtcod/libtcod.hpp"
#include "Game.hpp"

Game game;

int main(int argc, char *argv[])
{
    while(!TCODConsole::isWindowClosed()){
        game.update();
        game.render();
        TCODConsole::flush();
    }
    return 0;
}
