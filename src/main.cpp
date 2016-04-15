#include "libtcod/libtcod.hpp"
#include "Game.hpp"

const static int SCREEN_WIDTH = 80;
const static int SCREEN_HEIGHT = 50;

Game game(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char *argv[])
{
    while(!TCODConsole::isWindowClosed()){
        game.update();
        game.render();
        TCODConsole::flush();
    }
    return 0;
}
