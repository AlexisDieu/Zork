#include <iostream>
#include "Room.h"
#include "Exit.h"

Room::Room(const char * name, const char * description) : 
	Entity (name,description)
{

}

Room::~Room()
{
}
