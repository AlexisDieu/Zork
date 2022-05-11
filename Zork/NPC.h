#ifndef __NPC__
#define __NPC__

#include "Creature.h"
#include "Item.h"

using namespace std;

class NPC : public Creature
{

public:

	NPC(const char* name, const char* description, Room* room,bool interact);
	~NPC();

	void Interaction(std::vector<Entity*> entities);
	Item* NPCItem(std::vector<Entity*> entities);
	void setInteract(bool interact);

	bool interact;

private:

};

#endif //__NPC__