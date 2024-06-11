#include <iostream>
#include "world.h"

using namespace std;

int main() {

    World world;
    world.setup();

    string command;

    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "quit") {
            break;
        }

        world.processCommand(command);
    }

    return 0;
}