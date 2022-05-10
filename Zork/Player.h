#ifndef __Player__
#define __Player__

#include "Creature.h"

using namespace std;

class Player : public Creature
{

public:

	Player(const char* name,const char* description, Room* room);
	~Player();

	bool Movement(direction movement,std::vector<Entity*> entities);
	void Look() const;
	Room* GetRoom() const;
	void Update(Exit* exit);

private:

};

#endif //__Player__

