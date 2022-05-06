#ifndef __World__
#define __World__

#include <string>
#include <list>
#include <time.h>

using namespace std;

class Entity;
class Player;

class World
{

public :

	World();
	~World();

private:

	list<Entity*> entities;
	Player* player;

};

#endif //__World__