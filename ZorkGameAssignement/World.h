#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <string>
#include "Entity.h"

class World {
public:

    World() = default;
    ~World() = default;

    void setup();
    void processCommand(const std::string& command);

private:
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif