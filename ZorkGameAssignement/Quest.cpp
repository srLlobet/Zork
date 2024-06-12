#include "Quest.h"
#include "Creature.h" 
#include <iostream>

Quest::Quest(const string& name, const string& description, unique_ptr<Item> reward, unique_ptr<Quest> nextStep)
    : Entity(Entity::QUEST, name, description),
    reward(move(reward)),
    nextStep(move(nextStep)) {}

Quest::~Quest() {}

void Quest::checkObjective(const string& objective) {

}

void Quest::clearQuest() {
    if (nextStep) {
        cout << "quest updated";
        name = nextStep->name;
        description = nextStep->description;
        reward = move(nextStep->reward);
        nextStep = move(nextStep->nextStep);
    }
}   