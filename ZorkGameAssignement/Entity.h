#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>

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


protected:
    EntityType type;
    string name;
    string description;
    list<Entity*> containedEntities;
};

#endif


