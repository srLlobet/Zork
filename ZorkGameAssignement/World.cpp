#include "World.h"
#include "Room.h"
#include "Item.h"
#include <iostream>


void World::setup() {
    auto surface = make_unique<Room>("Arid wastelands - Depth 0m", "An arid wasteland spreads as far as you can see in any direction. This is it. This is where it begins. Your calling is upon you. Whenever you feel ready, you just need to dig deeper.");
    auto firstStrata = make_unique<Room>("First strata - Depth 20m", "You have reached the first stop on your long journey. The moist earth gradually turns to solid rock beneath your feet. You could continue digging deeper, but you can feel a sacred pull to the north. It seems the goddess of the depths has an altar just ahead, maybe you should seek her counsel and protection.");
    auto temple = make_unique<Room>("Temple of the Depths - Depth 20m", "You dig northwise, following the sacret aura, and eventually stumble upon a tiny cavern illuminated by torches. A stone statue of a woman sits in the center. You feel compelled to pray.");
    auto secondStrata = make_unique<Room>("Second strata - Depth 100m", "");

    auto shovel = make_unique<Item>("Trusted shovel", "Your best friend and trusted partner. Whenever you wield it, a heavenly aura empowers you making you feel like you can dig through tons of dirt.");

    surface->setItem(move(shovel));

    entities.push_back(move(surface));
    entities.push_back(move(firstStrata));
    entities.push_back(move(temple));
    entities.push_back(move(secondStrata));
}

void World::processCommand(const string& command) {

   
}
