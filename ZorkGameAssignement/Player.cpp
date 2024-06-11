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

void Player::dig() {
    currentRoom = currentRoom->getBelow();

    cout << currentRoom->getName() << "\n";
    cout << currentRoom->getDescription() << "\n";
    for (const auto& entity : currentRoom->getContainedEntities()) {
        cout << "A " << entity->getName() << " is here.\n";
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

