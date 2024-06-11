#include "Quest.h"
#include "Creature.h" 

Quest::Quest(const std::string& description, std::unique_ptr<Item> objective, std::unique_ptr<Quest> nextStep)
    : Entity(Entity::QUEST, "Quest", description),
    objective(std::move(objective)),
    nextStep(std::move(nextStep)),
    isCompleted(false) {}

Quest::~Quest() {}

void Quest::checkObjective() {

}

void Quest::clearQuest() {

}