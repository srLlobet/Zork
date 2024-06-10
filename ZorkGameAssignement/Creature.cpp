#include "Creature.h"

#include<string>

Creature::Creature(const string& name, const string& description, Room* room) :
	Entity(title, description, (Entity*)room) 