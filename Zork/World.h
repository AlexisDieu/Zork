#ifndef __World__
#define __World__

#include <string>
#include <vector>

using namespace std;

class Entity;
class Player;

class World
{

public :

	World();
	~World();

	bool GameCommand(string commandInput);

private:

	std::vector <Entity*> entities;
	Player* player;

};

#endif //__World__