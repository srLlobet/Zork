#include "Quest.h"
#include "Creature.h" 

Quest::Quest(const std::string& description, std::unique_ptr<Item> objective, std::unique_ptr<Quest> nextStep)
    : Entity(Entity::QUEST, "Quest", description),
    objective(std::move(objective)),
    nextStep(std::move(nextStep)),
    isCompleted(false) {}

Quest::~Quest() {}

void Quest::checkObjective() {
    // Check if the player has the objective item
    // Implement the logic to check the player's inventory
    if (/* Condition to check if the player has the objective item */) {
        clearQuest();
    }
}

void Quest::clearQuest() {
    isCompleted = true;
    // Handle what happens when the quest is cleared
    // For example, activate the next step if there is one
    if (nextStep) {
        // Logic to activate the next quest
    }
}