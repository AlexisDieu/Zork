#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include "Room.h"
#include "Player.h"

World::World() {

}

World::~World() 
{
	for (std::vector<Entity*>::iterator i = entities.begin(); i != entities.end(); ++i)
		delete *i;

	entities.clear();
}
