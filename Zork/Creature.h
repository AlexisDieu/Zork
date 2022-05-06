#ifndef __Creature__
#define __Creature__

#include <string>
#include "Entity.h"

using namespace std;
class Room;

class Creature : public Entity
{

public:

	Creature();
	~Creature();

	Room* location;

private:

};

#endif //__Creature__