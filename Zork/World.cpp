#include <iostream>
#include <string>
#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include "Room.h"
#include "Player.h"

using namespace std;

World::World() {

	// creation Rooms 

	Room* tree = new Room("Tree","There is a big old tree in the middle of nowhere");
	Room* farm = new Room("Farm","You can see a farm but nothing look to live in ...");
	Room* lac = new Room("Lac","There is a beautiful lac with a lot of grass around it");
	Room* railway = new Room("Railway","A railway pass between some tree but it's look not praticable for a train");
	Room* cave = new Room("Cave","You cannot go deeper actually the darkness don't allow you to see anything");

	//push the room in the vector
	entities.push_back(tree);
	entities.push_back(farm);
	entities.push_back(lac);
	entities.push_back(railway);
	entities.push_back(cave);

	// creation of exits
	Entity* treeExit = new Exit(EAST, WEST, "forest", "Small road between some trees", tree, farm);
	Entity* farmToLacExit = new Exit(NORTH, SOUTH, "lac", "A Down road that look to a lac", farm, lac);
	Entity* farmToRailwayExit = new Exit(SOUTH, NORTH, "path", "a rocky path that go to a railway", farm, railway);
	Entity* farmToCaveExit = new Exit(EAST, WEST, "mountain", "Mountainous road that bring to a cave", farm, cave);

	//push the exit in the vector
	entities.push_back(treeExit);
	entities.push_back(farmToLacExit);
	entities.push_back(farmToRailwayExit);
	entities.push_back(farmToCaveExit);

	// creation of the player with the map beginning

	player = new Player("Arthur", "a young knight", tree);
	entities.push_back(player);


}

World::~World() 
{
	for (std::vector<Entity*>::iterator i = entities.begin(); i != entities.end(); ++i)
		delete *i;

	entities.clear();
}

//check the input of the player to use command
bool World::GameCommand(string commandInput)
{
	bool val = true;
	//command to move on the map
	if (commandInput.compare("east")==0)
	{
		cout << "East ? \n";
		player->Movement(EAST, entities);
	}
	if (commandInput.compare("north") == 0)
	{
		cout << "North ? \n";
		player->Movement(NORTH, entities);
	}
	if (commandInput.compare("south") == 0)
	{
		cout << "South ? \n";
		player->Movement(SOUTH, entities);
	}
	if (commandInput.compare("west") == 0)
	{
		cout << "West ? \n";
		player->Movement(WEST, entities);
	}
	
	//command to look arround and get information of current map
	if (commandInput.compare("look")==0) 
	{
		cout << "Look ? \n";
		player->Look();
	}
	return val;
}
