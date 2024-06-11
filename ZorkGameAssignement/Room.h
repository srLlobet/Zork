#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Item.h"

class Room : public Entity {
public:

    Room(const string& name, const string& description);
    ~Room();

    void setItem(unique_ptr<Entity> setupItem);


    const vector<unique_ptr<Entity>>& getContainedEntities() const;

    //getters & setters for pointers to the room above and below
    void setAbove(shared_ptr<Room> room);
    void setBelow(shared_ptr<Room> room);
    shared_ptr<Room> getAbove() const;
    shared_ptr<Room> getBelow() const;
    
private:
    shared_ptr<Room> above;
    shared_ptr<Room> below;

};

#endif