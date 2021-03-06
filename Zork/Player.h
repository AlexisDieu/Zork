#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "NPC.h"
#include "Item.h"

using namespace std;

class Player : public Creature
{

public:

	Player(const char* name,const char* description, Room* room);
	~Player();

	bool Movement(direction movement,std::vector<Entity*> entities);
	void Look(std::vector<Entity*> entities) const;
	void UnLock(Exit* exit,std::vector<Entity*> entities) const;
	void Loot(std::vector<Entity*> entities,string commandInput);
	void FindItem(std::vector<Entity*> entities)const;
	void FindNPC(std::vector<Entity*> entities)const;
	void TalkNPC(std::vector<Entity*> entities)const;
	NPC* GetNPC(std::vector<Entity*> entities)const;
	void Inventory(std::vector<Entity*> entities);
	void Drop(std::vector<Entity*> entities,string commandInput);
	Room* GetRoom() const;
	void Update(Exit* exit);
	void EndGame(Exit* exit,std::vector<Entity*> entities);

private:

};

#endif //__Player__

