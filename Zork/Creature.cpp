#include "Creature.h"
#include <iostream>
#include <string>


Creature::Creature(const char * name, const char * description, Room * room) : 
	Entity(name,description)
{
	type = CREATURE;

}

Creature::~Creature()
{
}

Room * Creature::GetRoom() const
{
	//cout << location->GetName();
	return location ;
}
