#ifndef __Exit__
#define __Exit__

#include <string>
#include "Entity.h"

using namespace std;

enum direction
{
	UP,
	RIGHT,
	LEFT,
	DOWN
};

class Room;

class Exit : public Entity
{

public:

	Exit();
	~Exit();

	Room* destination;
	Room* source;

private:

};

#endif //__Exit__