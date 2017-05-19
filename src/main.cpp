#include <iostream>
#include "system.hpp"

int main(int argc, char *argv[])
{
    System sys;

    while(sys.running()) {
        sys.handleEvents();
        sys.update();
        sys.draw();
    }

    return EXIT_SUCCESS;
}
