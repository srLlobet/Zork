#include "Creature.h"

Creature::Creature(const string& name, const string& description, shared_ptr<Room> room) 
    : Entity(Entity::CREATURE, name, description), currentRoom(room) {}

Creature::~Creature() {}

void Creature::addQuest(unique_ptr<Quest> quest) {
    questList.push_back(move(quest));
}

vector<unique_ptr<Quest>>& Creature::getQuestList()
{
    return questList;
}

