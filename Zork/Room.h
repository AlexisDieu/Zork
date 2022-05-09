#ifndef __Room__
#define __Room__

#include <string>
#include "Entity.h"
#include "Exit.h"

using namespace std;

class Room : public Entity
{

public:

	Room(const char* name, const char* description);
	~Room();

	Exit* GetExit(const string& direction) const;
	string GetName();

private:

};

#endif //__Room__


