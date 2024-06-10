#include "World.h"
#include "Room.h"
#include "Item.h"
#include <iostream>
#include <sstream>


void World::setup() {
    auto surface = make_unique<Room>("Arid wastelands - Depth 0m", "An arid wasteland spreads as far as you can see in any direction. This is it. This is where it begins. Your calling is upon you. Whenever you feel ready, you just need to dig deeper.");
    auto firstStrata = make_unique<Room>("First strata - Depth 20m", "You have reached the first stop on your long journey. The moist earth gradually turns to solid rock beneath your feet. You could continue digging deeper, but you can feel a sacred pull to the north. It seems the goddess of the depths has an altar just ahead, maybe you should seek her counsel and protection.");
    auto temple = make_unique<Room>("Temple of the Depths - Depth 20m", "You dig northwise, following the sacret aura, and eventually stumble upon a tiny cavern illuminated by torches. A stone statue of a woman sits in the center. You feel compelled to pray.");
    auto secondStrata = make_unique<Room>("Second strata - Depth 100m", "cock");
    auto thirdStrata = make_unique<Room>("Third strata - Depth 300m", "uwu");
    auto depths = make_unique<Room>("The Depths - Depth 500m", "aaaaa");


    auto shovel = make_unique<Item>("Trusted shovel", "Your best friend and trusted partner. Whenever you wield it, a heavenly aura empowers you making you feel like you can dig through tons of dirt.");
    auto bucket = make_unique<Item>("Bucket", "An old metal bucket, it can be filled with liquids");
    auto talisman = make_unique<Item>("Talisman of the depths", "A talisman depicting the symbol of the depths. Part of an accessory collection. Getting all pieces might do something... ");
    auto water = make_unique<Item>("A big puddle of water", "It's a water puddle. Wet and refreshing");


    surface->setItem(move(shovel));
    temple->setItem(move(talisman));
    firstStrata->setItem(move(bucket));
    

    entities.push_back(move(surface));
    entities.push_back(move(firstStrata));
    entities.push_back(move(temple));
    entities.push_back(move(secondStrata));

    currentRoom = static_cast<Room*>(entities[0].get()); // Set the starting room
}

void World::processCommand(const string& command) {

    //multi-word commands
    istringstream iss(command);
    string action;
    string target;

    iss >> action;
    getline(iss >> ws, target);

    if (action == "look") {
        if (target.empty()) {
            
            cout << currentRoom->GetName() << "\n";
            cout << currentRoom->GetDescription() << "\n";
            // List items in the room
            for (const auto& entity : currentRoom->getContainedEntities()) {
                cout << "A " << entity->GetName() << " is here.\n";
            }
        }
        else {
            // Look for a specific item in the current room
            Entity* entity = currentRoom->FindEntity(target);
            if (entity) {
                std::cout << "You see: " << entity->GetDescription() << "\n";
            }
            else {
                std::cout << "There is no " << target << " here.\n";
            }
        }
    }
}
