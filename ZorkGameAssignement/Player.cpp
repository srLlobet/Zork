#include <iostream>
#include "Player.h"

Player::Player(const string& name, const string& description, shared_ptr<Room> room)
    : Creature(name, description, room){
    if (room) {
        currentRoom = room;
        look("");
    }
    else {
        cout << "Error: Room pointer is null!" << std::endl;
    }
}
Player::~Player() {}

void Player::look(const string& target) {
    if (target.empty()) {
        cout << currentRoom->getName() << "\n";
        cout << currentRoom->getDescription() << "\n";
        // List items in the room
        for (const auto& entity : currentRoom->getContainedEntities()) {
            cout << "A " << entity->getName() << " is here.\n";
        }
    }
    else {
        // Look for a specific item in the current room
        Entity* entity = currentRoom->findEntity(target);
        if (entity) {
            cout << "You see: " << entity->getDescription() << "\n";
        }
        else {
            cout << "There is no " << target << " here.\n";
        }
    }
}

void Player::dig() {
    if (currentRoom->getName() == "The Forge - Depth 300m"  && !findEntity("copper shovel")) {
        cout << "The ground is too tough for you to dig deeper. You should find a way to upgrade your shovel.";
    }
    else {
        currentRoom = currentRoom->getBelow();
        cout << currentRoom->getName() << "\n";
        cout << currentRoom->getDescription() << "\n";
        for (const auto& entity : currentRoom->getContainedEntities()) {
            cout << "A " << entity->getName() << " is here.\n";
        }
    }
}

void Player::climb() {
    currentRoom = currentRoom->getAbove();
    cout << currentRoom->getName() << "\n";
    cout << currentRoom->getDescription() << "\n";
    for (const auto& entity : currentRoom->getContainedEntities()) {
        cout << "A " << entity->getName() << " is here.\n";
    }
}

void Player::inventory() {
    for (const auto& entity : containedEntities) {
        cout << "A " << entity->getName() << "\n";
    }
}

void Player::take(const string& target) {
    unique_ptr<Entity> item = currentRoom->takeItem(target);
    if (item) {
        cout << "You take " << item->getName() << "\n";
        containedEntities.push_back(move(item));
    }
    else {
        cout << "There is no " << target << " here.\n";
    }
}

void Player::drop(const string& target) {
    auto it = std::find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
        return item->getName() == target;
        });

    if (it != containedEntities.end()) {
        std::unique_ptr<Entity> droppedItem = std::move(*it);
        containedEntities.erase(it); 
        currentRoom->setItem(move(droppedItem)); 
        std::cout << "You drop " << target << " in the room.\n";
    }
    else {
        std::cout << "You don't have a " << target << " to drop.\n";
    }
}

void Player::mine(const string& target) {
    auto it = std::find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
        return item->getName() == "pickaxe";
        });
    if (it != containedEntities.end()) {
        take(target);
    }
    else {
        cout << "You don't have a pickaxe to mine the ore";
    }
}


