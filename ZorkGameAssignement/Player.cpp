#include <iostream>
#include "Player.h"

Player::Player(const string& name, const string& description, shared_ptr<Room> room)
    : Creature(name, description, room){
    if (room) {
        currentRoom = room;
        look("");
        
    }
    else {
        cout << "Error: Room pointer is null!" << std::endl;
    }
}
Player::~Player() {}

void Player::look(const string& target) {
    if (target.empty()) {
        cout << currentRoom->getName() << "\n";
        cout << currentRoom->getDescription() << "\n";
        // List items in the room
        for (const auto& entity : currentRoom->getContainedEntities()) {
            cout << "A " << entity->getName() << " is here.\n";
        }
    }
    else {
        // Look for a specific item in the current room
        Entity* entity = currentRoom->findEntity(target);
        if (entity) {
            cout << "You see: " << entity->getDescription() << "\n";
        }
        else {
            cout << "There is no " << target << " here.\n";
        }
    }
}

void Player::dig() {
    if (currentRoom->getName() == "Arid wastelands - Depth 0m" && !findEntity("shovel")) {
        cout << "Can't dig down without your trusted shovel!";
    }
    else {
        if (currentRoom->getName() == "The Forge - Depth 300m" && !findEntity("copper shovel")) {
            cout << "The ground is too tough for you to dig deeper. You should find a way to upgrade your shovel.";

                auto it = find_if(questList.begin(), questList.end(), [&](const unique_ptr<Quest>& quest) {
                return quest->getName() == "Reach for the depths!";
                    });
                if (it != questList.end()) {
                    cout << "The quest " << (*it)->getName() << " has been updated.\n";
                    (*it)->clearQuest();
                }
        }
        else {
            currentRoom = currentRoom->getBelow();
            cout << currentRoom->getName() << "\n";
            cout << currentRoom->getDescription() << "\n";
            for (const auto& entity : currentRoom->getContainedEntities()) {
                cout << "A " << entity->getName() << " is here.\n";
            }
        }
    }
}

void Player::climb() {
    currentRoom = currentRoom->getAbove();
    cout << currentRoom->getName() << "\n";
    cout << currentRoom->getDescription() << "\n";
    for (const auto& entity : currentRoom->getContainedEntities()) {
        cout << "A " << entity->getName() << " is here.\n";
    }
}

void Player::inventory() {
    for (const auto& entity : containedEntities) {
        cout << "A " << entity->getName() << "\n";
    }
}

void Player::take(const string& target) {
    unique_ptr<Entity> item = currentRoom->takeItem(target);
    if (item) {
        cout << "You take " << item->getName() << "\n";
        containedEntities.push_back(move(item));
    }
    else {
        cout << "There is no " << target << " here.\n";
    }
}

void Player::drop(const string& target) {
    auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const unique_ptr<Entity>& item) {
        return item->getName() == target;
        });

    if (it != containedEntities.end()) {
        unique_ptr<Entity> droppedItem = move(*it);
        containedEntities.erase(it); 
        currentRoom->setItem(move(droppedItem)); 
        cout << "You drop " << target << " in the room.\n";
    }
    else {
        cout << "You don't have a " << target << " to drop.\n";
    }
}

void Player::mine(const string& target) {
    auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
        return item->getName() == "pickaxe";
        });
    if (it != containedEntities.end()) {
        take(target);
    }
    else {
        cout << "You don't have a pickaxe to mine the ore";
    }
}

void Player::printquest(const string& target) {
    if (target.empty()) {
        cout << "Quest: " << questList[0]->getName() << endl;
        cout << "Description: " << questList[0]->getDescription() << endl;
        auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
             return item->getName() == "pickaxe";
             });
         if (it != containedEntities.end()) {
            cout << "Quest: " << questList[1]->getName() << endl;
            cout << "Description: " << questList[1]->getDescription() << endl;
         }
         auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
             return item->getName() == "gold vein";
             });
         if (it != containedEntities.end()) {
             cout << "Quest: " << questList[2]->getName() << endl;
             cout << "Description: " << questList[2]->getDescription() << endl;
         }
        
    }
}

void Player::talk(const string& target) {
    if (target == "blacksmith" && (currentRoom->getName() == "The Forge - Depth 300m")) {
        if (blacksmithTalkCount == 0) {
            cout << "Ah, another madman comes through. Know that your quest shall end in harrowing death and despair, like the others who have come before you. Me? I am but a humble blacksmith, hammering my sorrow away.";
            cout << "You've found yourself at an impasse, huh? If you must continue your quest regardless, at least do it with a fair tool. Bring me some copper, and I'll get that shovel of yours up to the task";
            cout << "Take this pickaxe to get the copper";
            cout << "You've received a quest from the blacksmith!";
            blacksmithTalkCount++;

        }
        else {

        }
    }
}

