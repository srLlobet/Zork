#ifndef CREATURE_H
#define CREATURE_H

#include<string>
#include<memory>
#include<iostream>

#include"Room.h"
#include"Quest.h"

using namespace std;

class Creature : public Entity {
public:

    Creature(const string& name, const string& description, shared_ptr<Room> room);
    ~Creature();

    void addQuest(unique_ptr<Quest> quest);
    vector<unique_ptr<Quest>>& getQuestList();


protected:
    vector<unique_ptr<Quest>>  questList;
    shared_ptr<Room> currentRoom;
    
};

#endif
