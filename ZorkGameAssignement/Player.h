#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

using namespace std;

class Item : public Entity {
public:

    Item(const string& name, const string& description);
    ~Item();

    void Update() override;

    void Interact(Entity& source);

};

#endif