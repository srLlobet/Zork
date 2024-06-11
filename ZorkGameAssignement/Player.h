#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"


using namespace std;

class Player : public Creature{
public:

    Player(const string& name, const string& description, shared_ptr<Room> room);
    ~Player();


	bool dig();
	bool climb();
	void look(const string& target);
	bool take(const string& target);
	bool drop(const string& target);
	void inventory();
	bool pray(const string& target);
	bool talk(const string& target);
	bool give(const string& target);
	bool mine(const string& target);



private:
	shared_ptr<Room> currentRoom;
};

#endif