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

/*string enum_to_string(direction dir) {
	switch (dir) {
	case NORTH:
		return "north";
	case EAST:
		return "east";
	case WEST:
		return "west";
	case SOUTH:
		return "south";
	default:
		return "Invalid direction";
	}
}*/


class Room;

class Exit : public Entity
{

public:

	Exit(direction way, direction opposite_way,  const char* name, const char* description, Room* source, Room* destination);
	~Exit();

	Room* destination;
	Room* source;
	direction way;
	direction opposite_way;
	bool access;

	const string& GetName(const Room* room)const;
	direction GetWay()const;
	direction GetOpposite_Way()const;
	string GetSourceName()const;
	string GetDestinationName()const;

private:

};

#endif //__Exit__