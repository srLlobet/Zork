#ifndef CREATURE_H
#define CREATURE_H

#include<string>
#include<memory>

#include"Room.h"
#include"Quest.h"

using namespace std;

class Creature : public Entity {
public:

    Creature(const string& name, const string& description, Room* room);
    ~Creature();

    void addQuest(unique_ptr<Quest> quest);

    void Update() override;
    void Interact(Entity& source);

private:
    vector<unique_ptr<Quest>>  questList;
    shared_ptr<Room> currentRoom;
    
};

#endif
