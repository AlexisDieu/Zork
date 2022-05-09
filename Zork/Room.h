#ifndef __Room__
#define __Room__

#include <string>
#include <vector>
#include "Entity.h"
#include "Exit.h"

using namespace std;

class Room : public Entity
{

public:

	Room(const char* name, const char* description);
	~Room();

	Exit* GetExit(string room,direction directions, std::vector<Entity*> entities) const;
	string GetName()const;

private:

};

#endif //__Room__


