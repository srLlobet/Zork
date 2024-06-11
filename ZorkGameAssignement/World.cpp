#include "World.h"
#include "Room.h"
#include "Item.h"
#include "player.h"
#include <iostream>
#include <sstream>


void World::setup() {
    auto surface = make_shared<Room>("Arid wastelands - Depth 0m", "An arid wasteland spreads as far as you can see in any direction. This is it. This is where it begins. Your calling is upon you. Whenever you feel ready, you just need to dig deeper.");
    auto temple = make_shared<Room>("Temple of the Depths - Depth 20m", "A tiny cavern illuminated by torches stands before you. There is a stone statue of a woman sitting in the center of the room. It's the goddess of the depths. You feel compelled to pray.");
    auto cavern = make_shared<Room>("Moist Cavern - Depth 100m", "The admosphere is very humid. A thin white mist spreads around in all directions, and water droplets streak down the countless stalagmites of the cave. The walls are covered in moss and there is a thick smell of wet soil");
    auto forge = make_shared<Room>("The Forge - Depth 300m", "As soon as you enter the chamber, you feel an intense heat, and can hear the unmistakable clang of metal against metal. Around you lay thousands of broken weapons. From swords, to maces, to spears. ");
    auto depths = make_shared<Room>("The Depths - Depth 500m", "Countless small rocky pathways spread in all directions. They all feel dark and hostile. You are sure nobody has stepped down this far for decades.");
    auto magma = make_shared<Room>("Magma Caverns -  Depth 1.000m", "A massive heat wave assaults you as soon as you enter. The cavern shines. Filled with brilliant incandescent rock, and a river of magma courses through the space.");
    auto abyss = make_shared<Room>("The abyss - Depth 10.000m", "This is what you came here for. The bottom of the world. Before you stands an unfathomably deep hole. You look into it. You can't see the bottom.");
    auto beyond = make_shared<Room>("??? - Depth -1", "yOu sHoUld NoT HAvE GoNE So DeEP");


    auto shovel = make_unique<Item>("Trusted shovel", "Your best friend and trusted partner. Whenever you wield it, a heavenly aura empowers and you feel like you could dig for hours through any material.");
    auto copperShovel = make_unique<Item>("Copper shovel", "Your partner got an upgrade! You can now dig through the hardest of terrains.");
    auto bucket = make_unique<Item>("Bucket", "An old metal bucket, it can be filled with liquids");
    auto talisman = make_unique<Item>("Talisman of the depths", "A talisman depicting the symbol of the depths. Part of an accessory collection. Getting all pieces might do something... ");
    auto copper = make_unique<Item>("A copper vein", "Copper, one of the common materials. If you had a pickaxe, you could definetiley mine this. But then again, why would you?");
    auto gold = make_unique<Item>("A gold vein", "A shiny material that would definitely fetch a great price on the surface. If you could mine it, you would make a fortune. But is this really the reason you came this far?");
    auto mythril = make_unique<Item>("A vein of... mythril? ", "This... is definitely mythril, but it shouldn't be real. How does this exist and what is it doing down here?");
    auto water = make_unique<Item>("A big puddle of water", "It's water. Wet and refreshing");
    auto ring = make_unique<Item>("Ring of the depths", "A ring depicting the symbol of the depths.Part of an accessory collection. Getting all pieces might do something... ");
    auto necklace = make_unique<Item>("Necklace of the depths", "A ring depicting the symbol of the depths.Part of an accessory collection. Getting all pieces might do something... ");
    auto pickaxe = make_unique<Item>("Pickaxe", "A sturdy pickaxe with a diamont point. No rock will resist the impact");
    
    auto statue = make_unique<Creature>("Statue of the Goddess", "A statue depicting the goddess of the depths. It looks like it could come alive at any moment. The goddess blesses those who attempt to reach the depths. Praying before a delve is a good idea.", temple);
    auto blacksmith = make_unique<Creature>("Dwarven blacksmith", "An old disheveled man of small stature is here. Hammer in hand, he forges piece after piece, with seemingly no purpouse at all. ", forge);
    
    auto mainQuest3 = make_unique<Quest>("To the beyond!", "This is it! You've reached the bottom! Whenever you feel ready, plunge into the hole to find what you've been seeking all this time!", nullptr, nullptr);
    auto mainQuest2 = make_unique<Quest>("Reach for the depths! 2", "It seems like the ground is made of a much harder material. Your trusty old shovel might need an upgrade!", nullptr, move(mainQuest3));
    auto mainQuest = make_unique<Quest>("Reach for the depths!", "You are finally here. Everyone back home said you were crazy, but none shall stop you any longer! Chase your dreams and delve on the darkest of depths to find out what lies beyond!", nullptr, move(mainQuest2));

    auto smithQuest2 = make_unique<Quest>("A blacksmith's plea", "This old blacksmith has spend eons down here trying to forge one of the godly accessories, but he's missing a crucial ore. Mythril. Find it and bring it to him.", move(ring), nullptr);
    auto smithQuest = make_unique<Quest>("Forge!", "The blacksmith has agreed to upgrade your shovel if you can give him some copper.", move(copperShovel), move(smithQuest2));

    auto goldQuest = make_unique<Quest>("Golden opportunity", "You've found some gold, enough to make a small fortune outside. Thoughts of leaving and being rich plague your mind, but is that enough to sway your opinion? Your purpouse? You can head out now, but the goddess would appreciate your commitment if you left it all behind", nullptr, nullptr);

    surface->setItem(move(shovel));
    temple->setItem(move(talisman));
    cavern->setItem(move(copper));
    cavern->setItem(move(water));
    forge->setItem(move(bucket));
    magma->setItem(move(gold));
    abyss->setItem(move(mythril));
    
    surface->setBelow(temple);
    temple->setAbove(surface);
    temple->setBelow(cavern);
    cavern->setAbove(temple);
    cavern->setBelow(forge);
    forge->setAbove(cavern);
    forge->setBelow(depths);
    depths->setAbove(forge);
    depths->setBelow(magma);
    magma->setAbove(depths);
    magma->setBelow(abyss);
    abyss->setAbove(magma);
    abyss->setBelow(beyond);
    beyond->setAbove(abyss);


    rooms.push_back(move(surface));
    rooms.push_back(move(temple));
    rooms.push_back(move(cavern));
    rooms.push_back(move(forge));
    rooms.push_back(move(depths));
    rooms.push_back(move(magma));
    rooms.push_back(move(abyss));
    rooms.push_back(move(beyond));

     player = make_shared<Player>("Player", "The main character.", surface);

     
     player->addQuest(move(mainQuest));
     statue->addQuest(move(goldQuest));
     blacksmith->addQuest(move(smithQuest));
    
}

void World::processCommand(const string& command) {

    //multi-word commands
    istringstream iss(command);
    string action;
    string target;

    iss >> action;
    getline(iss >> ws, target);


    if (action == "look" || action == "l") {
        player->look(target);
    }
    else if (action == "inventory" || action == "i") {
        player->inventory();
    }
    else if (action == "dig") {
        player->dig();
    }
    else if (action == "climb") {
        player->climb();
    }
    else if (action == "take") {
        player->take(target);
    }
    else if (action == "drop") {
        player->drop(target);
    }

    else if (action == "pray") {
        player->pray(target);
    }
    else if (action == "talk") {
        player->talk(target);
    }
    else if (action == "give") {
        player->give(target);
    }
    else if (action == "mine") {
        player->mine(target);
    }
    else {
        std::cout << "Unknown command: " << action << "\n";
    }
}


