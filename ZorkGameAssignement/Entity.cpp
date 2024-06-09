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

void Entity::MoveEntityTo(Entity* entity, vector<Entity*>& destination) {
    auto it = remove(containedEntities.begin(), containedEntities.end(), entity);
    if (it != containedEntities.end()) {
        destination.push_back(entity);
        containedEntities.erase(it, containedEntities.end());
    }
}


Entity* Entity::FindEntity(const string& entityName) const {
    for (const auto& entity : containedEntities) {
        if (entity->GetName() == entityName) {
            return entity.get();
        }
    }
    return nullptr;
}