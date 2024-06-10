#ifndef QUEST_H
#define QUEST_H

#include "Entity.h"
#include "Item.h"
#include "Quest.h"


class Quest: public Entity
{
public:

	Quest(const string& description, unique_ptr<Item> objective, unique_ptr<Quest> nextStep);
	~Quest();

	void checkObjective();
	void clearQuest();

private:
	std::unique_ptr<Item> objective;
	std::unique_ptr<Quest> nextStep;
	bool isCompleted;

};


#endif
