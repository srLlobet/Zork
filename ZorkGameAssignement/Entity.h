#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Entity {
    
public:
    enum EntityType {
        CREATURE,
        ROOM,
        ITEM,
        QUEST,
    };

    Entity(EntityType type, const string& name, const string& description);

    virtual ~Entity();
    virtual void Update() = 0;

    const string& GetName() const; 
    const string& GetDescription() const; 

    void MoveEntityTo(Entity* entity, vector<Entity*>& destination);
    Entity* FindEntity(const string& entityName) const;



protected:
    EntityType type;
    string name;
    string description;
    vector<unique_ptr<Entity>> containedEntities;

    static const size_t MAX_ENTITIES = 3;
};

#endif


