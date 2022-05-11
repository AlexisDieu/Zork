#include <iostream>
#include <string>
#include "Room.h"
#include "Exit.h"

Room::Room(const char* name, const char* description) : 
	Entity (name,description)
{
	type = ROOM;

}

Room::~Room()
{
}

Exit * Room::GetExit(string room,direction directions, std::vector<Entity*> entities) const
{
	int allRoom = 0;
	//a while to check if the direction give in input is good with the actual room
	while( allRoom< (int)entities.size()) 
	{

		for (std::size_t i = 0; i <(int)entities.size(); i++) 
		{
			if (entities[i]->type == EXIT)
			{
				Exit* ex = (Exit*)entities[i];

					if (room.compare(ex->GetSourceName())==0)
					{
						if (directions == ex->GetWay())
						{
							if (Locked(ex) == true)
							{
								cout << "good way \n";
								return ex;
							}
							else if (ex->access == true)
							{
								return nullptr;
							}
							else return ex;
						}
					}
					else if (room.compare(ex->GetDestinationName())==0)
					{
						if (directions == ex->GetOpposite_Way())
						{
							if (Locked(ex) == true)
							{
								cout << "you turn back \n";
								return ex;
							}
							else if (ex->access == true)
							{
								return nullptr;
							}
							else return ex;
						}
					}
			allRoom++;
			}
		}
	}
	cout << "No way available \n";
	return nullptr;
}

bool Room::Locked(Exit* ex) const
{
	if (ex->access == true)
	{
		return true;
	}
	else
	{
		cout << "You need a " << ex->itemOpen->GetName() << " to go this way \n";
		return false;
	}
}

string Room::GetName()const
{
	return name;
}
