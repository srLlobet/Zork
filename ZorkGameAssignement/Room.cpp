#include "Room.h"

#include <iostream>


Room::Room(const string& name, const string& description)
    : Entity(Entity::ROOM, name, description) {}

Room::~Room() {

}

void Room::setItem(unique_ptr<Entity> setupItem) {
    containedEntities.push_back(move(setupItem));
}

const vector<unique_ptr<Entity>>& Room::getContainedEntities() const {
    return containedEntities;
}

void Room::Update() {
}