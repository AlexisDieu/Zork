#ifndef __Entity__
#define __Entity__

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{

public:

	Entity(const char* name,const char* description);
	virtual ~Entity();

	virtual void Update();

	EntityType type;
	std::string name;
	std::string description;

	string GetName()const;

	list<Entity*> contains;


private:

};

#endif //__Entity__
