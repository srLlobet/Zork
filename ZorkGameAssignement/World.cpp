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
    Room* surface = new Room("Arid wastelands - Depth 0m", "An arid wasteland spreads as far as you can see in any direction. This is it. This is where it begins. Your calling is upon you. Whenever you feel ready, you just need to dig deeper.");
    Room* firstStrata = new Room("First strata - Depth 20m", "You have reached the first stop on your long journey. The moist earth gradually turns to solid rock beneath your feet. You could continue digging deeper, but you can feel a sacred pull to the north. It seems the goddess of the depths has an altar just ahead, maybe you should seek her counsel and protection.");
    Room* temple = new Room("Temple of the Depths - Depth 20m", "You dig northwise, following the sacret aura, and eventually stumble upon a tiny cavern illuminated by torches. A stone statue of a woman sits in the center. You feel compelled to pray.");
    Room* secondStrata = new Room("Second strata - Depth 100m", "")
    entities.push_back(surface);
}

void World::processCommand(const std::string& command) {

   
}
