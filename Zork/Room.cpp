#include <iostream>
#include "Room.h"
#include "Exit.h"

Room::Room(const char* name, const char* description) : 
	Entity (name,description)
{

}

Room::~Room()
{
}

Exit * Room::GetExit(const string & direction) const
{
	for (list<Entity*>::const_iterator i = contains.begin(); i != contains.cend(); ++i)
	{
		if ((*i)->type == EXIT)
		{
			Exit* exit = (Exit*)*i;
			if (exit->GetName(this) == direction)
			{
				return exit;
			}
		}
	}
	return nullptr;
}
