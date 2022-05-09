#ifndef __Creature__
#define __Creature__

#include <string>
#include <vector>
#include "Entity.h"
#include "Room.h"
#include "Exit.h"

using namespace std;
class Room;

class Creature : public Entity
{

public:

	Creature(const char* name, const char* description, Room* room);
	~Creature();

	Room* location;
	Room* GetRoom() const;

private:

};

#endif //__Creature__