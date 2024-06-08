#include "World.h"
#include "Room.h"
#include <iostream>

World::World() {}

World::~World() {
    for (auto entity : entities) {
        delete entity;
    }
}

void World::setup() {
    Room* room = new Room("Overworld - Depth 0m", "This is it. This is where it begins. There is not turning back now. Your calling is upon you. Whenever you feel ready, you just need to dig deeper.");
    entities.push_back(room);
}

void World::processCommand(const std::string& command) {

   
}
