#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include "Entity.h"

class World {
public:

    World();
    ~World();

    void setup();
    void processCommand(const std::string& command);

private:
    std::vector<Entity*> entities;
};

#endif