#ifndef __Room__
#define __Room__

#include <string>
#include "Entity.h"

using namespace std;

class Room : public Entity
{

public:

	Room(const char* name, const char* description);
	~Room();

private:

};

#endif //__Room__


