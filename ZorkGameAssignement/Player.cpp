#include <iostream>
#include "Player.h"

Player::Player(const string& name, const string& description, shared_ptr<Room> room)
    : Creature(name, description, room), currentRoom(room) {}

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