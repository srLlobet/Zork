#include <iostream>
#include "world.h"


int main() {

    World world;
    world.setup();

    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "quit") {
            break;
        }

        world.processCommand(command);
    }

    return 0;
}