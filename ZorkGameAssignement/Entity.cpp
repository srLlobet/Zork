#include "Entity.h"

Entity::Entity(EntityType type, const string& name, const string& description)
    : type(type), name(name), description(description) {}

Entity::~Entity() {}

//ensures caller can't modify returned string

const string& Entity::GetName() const {
    return name;
}

const string& Entity::GetDescription() const {
    return description;
}