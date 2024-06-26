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


    const string& getName() const; 
    const string& getDescription() const; 
    
    Entity* findEntity(const string& entityName) const;
    


protected:
    EntityType type;
    string name;
    string description;
    vector<unique_ptr<Entity>> containedEntities;

};

#endif


