#include <iostream>
#include "config.hpp"
#include "system.hpp"

int main(int argc, char *argv[])
{
    Config config = getConfig("Dargon");
    System sys(config);

    while(sys.running()) {
        sys.update();
        sys.draw();
    }

    return EXIT_SUCCESS;
}
