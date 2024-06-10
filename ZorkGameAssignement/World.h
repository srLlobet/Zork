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

    //not a smart pointer because it doesn't own the room
    Room* currentRoom = nullptr;
};

#endif