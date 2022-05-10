#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "Item.h"

using namespace std;

class Player : public Creature
{

public:

	Player(const char* name,const char* description, Room* room);
	~Player();

	bool Movement(direction movement,std::vector<Entity*> entities);
	void Look(std::vector<Entity*> entities) const;
	void Loot(std::vector<Entity*> entities,string commandInput);
	void FindItem(std::vector<Entity*> entities)const;
	void Inventory(std::vector<Entity*> entities);
	void Drop(std::vector<Entity*> entities,string commandInput);
	Room* GetRoom() const;
	void Update(Exit* exit);

private:

};

#endif //__Player__

