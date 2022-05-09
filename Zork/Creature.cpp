#include "Creature.h"
#include <iostream>
#include <string>
#include <stdlib.h>


Creature::Creature(const char * name, const char * description, Room * room) : 
	Entity(name,description)
{
	type = CREATURE;
	location = room;

}

Creature::~Creature()
{
}

Room * Creature::GetRoom() const
{
	return location;
}

