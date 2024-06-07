#include "World.h"
#include <iostream>

World::World() {}

World::~World() {
    for (auto entity : entities) {
        delete entity;
    }
}

void World::setup() {

}

void World::processCommand(const std::string& command) {

   
}
