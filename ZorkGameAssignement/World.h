#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <string>
#include "Room.h"
#include "Player.h"

using namespace std;

class World {
public:

    World() = default;
    ~World() = default;

    void setup();
    void processCommand(const string& command);

private:
    vector<shared_ptr<Room>> rooms;
    shared_ptr<Player> player = nullptr; // Declare player as a member variable

};

#endif