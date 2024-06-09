#include "Room.h"
#include <iostream>

Room::Room(const std::string& name, const std::string& description)
    : Entity(Entity::ROOM, name, description) {}

Room::~Room() {
    for (Entity* entity : containedEntities) {
        delete entity;
    }
}

void Room::Update() {
}