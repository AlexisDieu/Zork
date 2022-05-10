#ifndef __Exit__
#define __Exit__

#include <string>
#include "Entity.h"

using namespace std;

enum direction
{
	NORTH,
	EAST,
	WEST,
	SOUTH
};

class Room;

class Exit : public Entity
{

public:

	Exit(direction way, direction opposite_way,  const char* name, const char* description, Room* source, Room* destination,bool access,Entity* itemOpen);
	~Exit();

	Room* destination;
	Room* source;
	direction way;
	direction opposite_way;
	bool access;
	Entity* itemOpen;

	const string& GetName(const Room* room)const;
	direction GetWay()const;
	direction GetOpposite_Way()const;
	string GetSourceName()const;
	string GetDestinationName()const;

private:

};

#endif //__Exit__