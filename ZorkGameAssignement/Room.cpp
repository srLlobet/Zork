#include "Room.h"

#include <iostream>


Room::Room(const string& name, const string& description)
    : Entity(Entity::ROOM, name, description) {}
Room::~Room() {

}

void Room::setItem(unique_ptr<Entity> setupItem) {
    containedEntities.push_back(move(setupItem));
}

unique_ptr<Entity> Room::takeItem(const string& itemName) {
    auto it = std::find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
        return item->getName() == itemName;
        });

    if (it != containedEntities.end()) {
        std::unique_ptr<Entity> takenItem = std::move(*it); 
        containedEntities.erase(it); 
        return takenItem;
    }

    return nullptr; // Item not found
}

const vector<unique_ptr<Entity>>& Room::getContainedEntities() const {
    return containedEntities;
}

void Room::setAbove(shared_ptr<Room> room) {
    above = room;
}

void Room::setBelow(shared_ptr<Room> room) {
    below = room;
}

shared_ptr<Room> Room::getAbove() const {
    return above;
}

shared_ptr<Room> Room::getBelow() const {
    return below;
}
