#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include "Room.h"
#include "Player.h"

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
	Exit* treeExit = new Exit(EAST, WEST, "forest", "Small road between some trees", tree, farm);
	Exit* farmToLacExit = new Exit(NORTH, SOUTH, "lac", "A Down road that look to a lac", farm, lac);
	Exit* farmToRailwayExit = new Exit(SOUTH, NORTH, "path", "a rocky path that go to a railway", farm, railway);
	Exit* farmToCaveExit = new Exit(EAST, WEST, "mountain", "Mountainous road that bring to a cave", farm, cave);

	//push the exit in the vector
	entities.push_back(treeExit);
	entities.push_back(farmToLacExit);
	entities.push_back(farmToRailwayExit);
	entities.push_back(farmToCaveExit);


}

World::~World() 
{
	for (std::vector<Entity*>::iterator i = entities.begin(); i != entities.end(); ++i)
		delete *i;

	entities.clear();
}
