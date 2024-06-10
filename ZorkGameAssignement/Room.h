#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Item.h"

using namespace std;

class Room : public Entity {
public:

    Room(const string& name, const string& description);
    ~Room();

    void setItem(unique_ptr<Entity> setupItem);
    void Update() override;

    const vector<unique_ptr<Entity>>& getContainedEntities() const;


};

#endif