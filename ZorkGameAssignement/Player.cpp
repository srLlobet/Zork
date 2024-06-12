#include <iostream>
#include "Player.h"

//Player constructor
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

bool Player::ending()
{
    return gameOver;
}
//movement and checks for certain items in inventory
void Player::dig() {
    if (!findEntity("shovel") && !findEntity("copper shovel")) {
        cout << "Can't dig down without your trusted shovel!";
    }
    else {
        if (currentRoom->getName() == "The Forge - Depth 300m" && !findEntity("copper shovel")) {
            cout << "The ground is too tough for you to dig deeper. You should find a way to upgrade your shovel.";
                //lambda function to search
                auto it = find_if(questList.begin(), questList.end(), [&](const unique_ptr<Quest>& quest) {
                return quest->getName() == "Reach for the depths!";
                    });
                if (it != questList.end()) {
                    cout << "The quest " << (*it)->getName() << " has been updated.\n";
                    (*it)->clearQuest();
                }
        }
        else if (currentRoom->getName() == "??? - Depth -1" && (!findEntity("talisman") || !findEntity("ring") || !findEntity("necklace"))) {
                cout << currentRoom->getName() << "\n";
                cout << currentRoom->getDescription() << "\n";
                cout << "You feel dizzy. You were not prepared. Your mind struggles to comprehend the shapes, colors and sounds that sorround you. You feel a wave of sleep coming. You close your eyes. You die. PRESS ENTER. \n";
                cin.ignore();
                gameOver = true;
            }
            else if (currentRoom->getName() == "??? - Depth -1" && (findEntity("talisman") && findEntity("ring") && findEntity("necklace"))) {
                cout << currentRoom->getName() << "\n";
                cout << currentRoom->getDescription() << "\n";
                cout << "The voice rips through your mind like a pancake, but the accessories you wear shine with the power of a thousand suns. Breaking through the darkness that surronds you, letting you see what lies beyond\n";
                cout << "You find a PC with a League of Legends main menu open, the mouse hovering the play button. Of course... PRESS ENTER";
                cin.ignore();
                gameOver = true;
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
    if (findEntity("gold vein") && currentRoom->getName() == "Arid wastelands - Depth 0m") {
        cout << "You have chosen to escape with a fortune. A wise choice, some might say. But you'll never now what lies beyond. PRESS ENTER";
        cin.ignore();
        gameOver = true;
    }
}

void Player::inventory() {
    for (const auto& entity : containedEntities) {
        cout << "A " << entity->getName() << "\n";
    }
}

void Player::take(const string& target) {
    if (target == "pickaxe" && blacksmithTalkCount == 0) {
        cout << "You don't have permission to take this item. Talk to the blacksmith first.";
    }
    else {
        if (target.find("vein") != string::npos) {
            cout << "you can't take this! It's embedded in the wall!";
        }
        else {
            unique_ptr<Entity> item = currentRoom->takeItem(target);
            if (item) {
                cout << "You take " << item->getName() << "\n";
                containedEntities.push_back(move(item));
            }
            else {
                cout << "There is no " << target << " here.\n";
            }
        }
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
        if (currentRoom->getName() == "Temple of the Depths - Depth 20m" && target == "gold vein") {
            cout << "You drop the gold beneath the statue's feet. For a moment, you feel like the goddess smiles at you fondly. \n";
            cout << "Quest updated! \n";
            cout << "You got a ring!";
            containedEntities.push_back(questList[2]->takeReward());
        }
        else {
            cout << "You drop " << target << " in the room.\n";
        }
        
    }
    else {
        cout << "You don't have a " << target << " to drop.\n";
    }
}

void Player::mine(const string& target) {
    if(!findEntity("pickaxe") && target.find("vein")) {
        cout << "You don't have a pickaxe to mine the ore";
    }
    else {
        unique_ptr<Entity> item = currentRoom->takeItem(target);
        if (item) {
            cout << "You mine out the " << item->getName() << "\n";
            containedEntities.push_back(move(item));
            if (target == "gold vein") {
                cout << "you found some gold! \n";
                cout << "new quest recieved! \n";
            }
        }
    }
}
//handles the quest list
void Player::printquest(const string& target) {
    if (target.empty()) {
        cout << "Quest: " << questList[0]->getName() << endl;
        cout << "\n Description: " << questList[0]->getDescription() << endl;

        auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
            return item->getName() == "pickaxe";
            });
        if (it != containedEntities.end()) {
            cout << "\n Quest: " << questList[1]->getName() << endl;
            cout << "\n Description: " << questList[1]->getDescription() << endl;
        }

        auto itt = find_if(containedEntities.begin(), containedEntities.end(), [&](const std::unique_ptr<Entity>& item) {
            return item->getName() == "gold vein";
            });
        if (itt != containedEntities.end()) {
            cout << " \nQuest: " << questList[2]->getName() << endl;
            cout << " \n Description: " << questList[2]->getDescription() << endl;
        }
        
    }
}

void Player::talk(const string& target) {
    if (target == "blacksmith" && (currentRoom->getName() == "The Forge - Depth 300m")) {
        if (blacksmithTalkCount == 0) {
            cout << "Ah, another madman comes through. Know that your quest shall end in harrowing death and despair, like the others who have come before you. Me? I am but a humble blacksmith, hammering my sorrow away. \n";
            cout << "You've found yourself at an impasse, huh? If you must continue your quest regardless, at least do it with a fair tool. Bring me some copper, and I'll get that shovel of yours up to the task \n";
            cout << "Take this pickaxe to get the copper \n";
            cout << "You've received a quest from the blacksmith! \n";
            blacksmithTalkCount++;

        }
        else if(blacksmithTalkCount >= 1 && blacksmithTalkCount < 90) {
            auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const unique_ptr<Entity>& item) {
                return item->getName() == "shovel";
                });
            auto itt = find_if(containedEntities.begin(), containedEntities.end(), [&](const unique_ptr<Entity>& item2) {
                return item2->getName() == "copper vein";
                });
            if (it != containedEntities.end() || itt != containedEntities.end()) {
                cout << "Just find me some copper and drop it and your shovel here.";
            }
            else {
                cout << "great! Here ya go! \n";
                cout << "Your got a copper shovel! \n";
                containedEntities.push_back(questList[1]->takeReward());
                cout << "maybe you can do me another favor, i'll give ya something worthwhile. \n";
                cout << "quest updated! \n";
                questList[1]->clearQuest();
                questList[0]->clearQuest();
                blacksmithTalkCount = blacksmithTalkCount + 99;
            }
        } else{
            auto it = find_if(containedEntities.begin(), containedEntities.end(), [&](const unique_ptr<Entity>& item) {
                return item->getName() == "mythril";
                });
            if (it != containedEntities.end() || it != containedEntities.end()) {
                cout << "Bring me some mythril, please. \n";
            }
            else {
                cout << "In-incredible! What great metal! Where did you even find this!? \n";
                cout << "My dreams of creating a masterpiece have finally come true. Here, take this. It's a necklace of the deep, if you have the three acessories, you will survive what lies beyond. \n";
                containedEntities.push_back(questList[1]->takeReward());
            }
        }
    }
}

