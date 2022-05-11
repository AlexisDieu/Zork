#include <iostream>
#include <string>
#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include "Room.h"
#include "Player.h"
#include "NPC.h"

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

	//creation of items in the map

	Item* treeHole = new Item("tree", "the tree seems to have a hole with something in", false, tree);
	Item* letter = new Item("letter", "A letter with something write in", true, treeHole);
	Item* torch = new Item("torch", "A torch already able to be fired", true, railway);


	entities.push_back(treeHole);
	entities.push_back(letter);
	entities.push_back(torch);

	// creation of exits
	Exit* treeExit = new Exit(EAST, WEST, "forest", "Small road between some trees", tree, farm,true,NULL);
	Exit* farmToLacExit = new Exit(NORTH, SOUTH, "lac", "A Down road that look to a lac", farm, lac,true,NULL);
	Exit* farmToRailwayExit = new Exit(SOUTH, NORTH, "path", "a rocky path that go to a railway", farm, railway,true,NULL);
	Exit* farmToCaveExit = new Exit(EAST, WEST, "mountain", "Mountainous road that bring to a cave", farm, cave,false,torch);

	//push the exit in the vector
	entities.push_back(treeExit);
	entities.push_back(farmToLacExit);
	entities.push_back(farmToRailwayExit);
	entities.push_back(farmToCaveExit);

	// creation of the creature

	Creature* troll = new Creature("Troll", "a big strong Troll", cave);
	entities.push_back(troll);	

	// creation of the NPC and his inventory

	NPC* fisherman = new NPC("Alexis", "An old man with a fishing rod ", lac,true);
	Item* fishingRod = new Item("rod", "A fishing rod that look really unused ", true, fisherman);
	entities.push_back(fisherman);
	entities.push_back(fishingRod);

	// creation of the player

	player = new Player("Arthur", "a young man", tree);
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
		cout << "Go to East \n";
		player->Movement(EAST, entities);
	}
	if (commandInput.compare("north") == 0)
	{
		cout << "Go to North \n";
		player->Movement(NORTH, entities);
	}
	if (commandInput.compare("south") == 0)
	{
		cout << "Go to South \n";
		player->Movement(SOUTH, entities);
	}
	if (commandInput.compare("west") == 0)
	{
		cout << "Go to West \n";
		player->Movement(WEST, entities);
	}
	
	//command to look arround and get information of current map
	if (commandInput.compare("look")==0) 
	{
		cout << "You look around \n";
		player->Look(entities);
	}
	//command to loot an item on the map
	if (commandInput.compare("loot")==0 || commandInput.compare("take") == 0)
	{
		cout << "You try to loot something \n";
		player->FindItem(entities);

		cout << "What you want to take ? \n";
		cin >> commandInput;
		player->Loot(entities,commandInput);
	}
	//command to check the inventory
	if (commandInput.compare("inventory") == 0)
	{
		cout << "Your inventory : \n";
		player->Inventory(entities);
	}
	//command to drop an item
	if (commandInput.compare("drop") == 0)
	{
		cout << "choose an item to drop \n";
		player->Inventory(entities);
		cin >> commandInput;
		player->Drop(entities,commandInput);
	}
	if (commandInput.compare("talk") == 0)
	{
		cout << "You talk with the person near you \n";
		player->TalkNPC(entities);
	}
	return val;
}
