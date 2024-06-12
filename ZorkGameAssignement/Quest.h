#ifndef QUEST_H
#define QUEST_H

#include "Entity.h"
#include "Item.h"
#include "Quest.h"


class Quest: public Entity
{
public:

	Quest(const string& name,const string& description, unique_ptr<Item> reward, unique_ptr<Quest> nextStep);
	~Quest();

	void checkObjective(const string& objective);
	void clearQuest();



private:
	unique_ptr<Item> reward;
	unique_ptr<Quest> nextStep;

};


#endif
