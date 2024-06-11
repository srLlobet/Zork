#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"


using namespace std;

class Player : public Creature{
public:

    Player(const string& name, const string& description, shared_ptr<Room> room);
    ~Player();


	void dig();
	void climb();
	void look(const string& target);
	void inventory();
	void take(const string& target);
	void drop(const string& target);
	void mine(const string& target);

	void pray(const string& target);
	void talk(const string& target);

	void give(const string& target);




private:
	shared_ptr<Room> currentRoom;
};

#endif