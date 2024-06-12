#ifndef QUEST_H
#define QUEST_H

#include "Entity.h"
#include "Item.h"
#include "Quest.h"


class Quest: public Entity
{
public:

	Quest(const string& name,const string& description, unique_ptr<Entity> reward, unique_ptr<Quest> nextStep);
	~Quest();

	unique_ptr<Entity> takeReward();
	void clearQuest();



private:
	unique_ptr<Entity> reward;
	unique_ptr<Quest> nextStep;

};


#endif
