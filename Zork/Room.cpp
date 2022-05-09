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
	cout << "test\n";
	for (std::size_t i = 0; i <(int)entities.size(); i++) {
		if (entities[i]->type == EXIT)
		{
			cout << entities[i]->GetName();
			Exit* ex = (Exit*)entities[i];
			cout << ex->GetWay();
			cout << "\n";
			cout << directions;
			if (room.compare(ex->GetSourceName()))
			{
				if (directions == ex->GetWay())
				{
					cout << entities[i]->GetName();
					cout << "nice \n";
				}
			}
			else if (room.compare(ex->GetDestinationName()))
			{
				if (directions == ex->GetOpposite_Way())
				{
					cout << entities[i]->GetName();
					cout << "nice \n";
				}
			}
		}
	}
	return nullptr;
}

string Room::GetName()const
{
	return name;
}
