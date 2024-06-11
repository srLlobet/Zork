#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description)
    : Entity(Entity::ITEM, name, description) {}

Item::~Item() {

}


void Item::interact(Entity& source)
{

}
