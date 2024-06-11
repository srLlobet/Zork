#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <string>
#include "Room.h"

using namespace std;

class World {
public:

    World() = default;
    ~World() = default;

    void setup();
    void processCommand(const string& command);

private:
    vector<shared_ptr<Room>> rooms;
    shared_ptr<Player> player; // Declare player as a member variable

    // Other member variables and functions...
};

#endif