#include "Entity.h"

Entity::Entity(EntityType type, const string& name, const string& description)
    : type(type), name(name), description(description) {}

Entity::~Entity() {}


const string& Entity::getName() const {
    return name;
}

const string& Entity::getDescription() const {
    return description;
}
//moves an entity from the source vector to destination vector
void MoveEntity(unique_ptr<Entity>& entity, vector<unique_ptr<Entity>>& source, vector<unique_ptr<Entity>>& destination) {
    auto it = find_if(source.begin(), source.end(), [&entity](const unique_ptr<Entity>& ptr) {
        return ptr.get() == entity.get();
        });

    if (it != source.end()) {
        destination.push_back(move(*it)); // Move the smart pointer
        source.erase(it); // Erase the smart pointer from the source
    }
}

//finds an entity with a given name
Entity* Entity::findEntity(const string& entityName) const {
    for (const auto& entity : containedEntities) {
        if (entity->getName() == entityName) {
            return entity.get();
        }
    }
    return nullptr;
}
