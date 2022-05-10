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
	while( allRoom< (int)entities.size()) 
	{

		for (std::size_t i = 0; i <(int)entities.size(); i++) 
		{
			if (entities[i]->type == EXIT)
			{
				//cout << entities[i]->GetName();
				//cout << "\n";
				Exit* ex = (Exit*)entities[i];
				//cout << ex->GetWay();
				//cout << ex->GetOpposite_Way();
				//cout << "\n";
				//cout << ex->GetSourceName();
				if (room.compare(ex->GetSourceName())==0)
				{
					if (directions == ex->GetWay())
					{
						cout << "good way \n";
						return ex;
					}
				}
				else if (room.compare(ex->GetDestinationName())==0)
				{
					if (directions == ex->GetOpposite_Way())
					{
						cout << "you turn back \n";
						return ex;
					}
				}
			allRoom++;
			}
		}
	}
	cout << "No way available \n";
	return nullptr;
}

string Room::GetName()const
{
	return name;
}
