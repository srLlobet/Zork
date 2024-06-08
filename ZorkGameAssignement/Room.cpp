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

void Room::AddEntity(Entity* entity) {
    containedEntities.push_back(entity);
}

void Room::RemoveEntity(Entity* entity) {
    containedEntities.remove(entity);
}

const std::vector<Entity*>& Room::GetContainedEntities() const {
    return containedEntities;
}