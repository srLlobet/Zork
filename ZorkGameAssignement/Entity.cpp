#include "Entity.h"

Entity::Entity(EntityType type, const string& name, const string& description)
    : type(type), name(name), description(description) {}

Entity::~Entity() {}


const string& Entity::GetName() const {
    return name;
}

const string& Entity::GetDescription() const {
    return description;
}

void Entity::MoveEntityTo(Entity* entity, std::vector<Entity*>& destination) {
    //sets pointer to entity to be removed from actual container
    auto it = std::remove(containedEntities.begin(), containedEntities.end(), entity);
    if (it != containedEntities.end()) {
        destination.push_back(entity);
        containedEntities.erase(it, containedEntities.end());
    }
}

//returns an entity contained in the entity based on name
Entity* Entity::FindEntity(const std::string& entityName) const {
    for (Entity* entity : containedEntities) {
        if (entity->GetName() == entityName) {
            return entity;
        }
    }
    return nullptr;
}