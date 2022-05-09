#ifndef __Player__
#define __Player__

#include "Creature.h"

using namespace std;

class Player : public Creature
{

public:

	Player(const char* name,const char* description, Room* room);
	~Player();

	bool Movement(const string movement);
	void Look() const;

private:

};

#endif //__Player__

