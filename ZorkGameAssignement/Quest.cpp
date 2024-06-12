#include "Quest.h"
#include "Creature.h" 
#include <iostream>

Quest::Quest(const string& name, const string& description, unique_ptr<Entity> reward, unique_ptr<Quest> nextStep)
    : Entity(Entity::QUEST, name, description),
    reward(move(reward)),
    nextStep(move(nextStep)) {}

Quest::~Quest() {}

unique_ptr<Entity> Quest::takeReward() {
    return move(reward);
}

void Quest::clearQuest() {
    if (nextStep) {
        name = nextStep->name;
        description = nextStep->description;
        reward = move(nextStep->reward);
        nextStep = move(nextStep->nextStep);
    }
}   