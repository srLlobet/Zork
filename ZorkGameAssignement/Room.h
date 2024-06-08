#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include <vector>

using namespace std;

class Room : public Entity {
public:

    Room(const string& name, const string& description);
    ~Room();

    void Update() override;

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    const vector<Entity*>& GetContainedEntities() const;

};

#endif