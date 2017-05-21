#include <SDL_timer.h>
#include <iostream>
#include "config.hpp"
#include "system.hpp"

Config config = getConfig("Dargon");
const Uint32 TICKS_PER_SECOND = 1000 / config.fps;

int main(int argc, char *argv[])
{
    System sys(config);

    while(sys.running()) {
        Uint32 start_ticks = SDL_GetTicks();

        sys.update();
        sys.draw();

        Uint32 deltaTime = SDL_GetTicks() - start_ticks;
        if(deltaTime < TICKS_PER_SECOND) {
            SDL_Delay(TICKS_PER_SECOND - deltaTime);
        }
    }

    return EXIT_SUCCESS;
}
