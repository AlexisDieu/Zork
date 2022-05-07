#include "Exit.h"
#include "Room.h"
#include <iostream>

Exit::Exit(direction way, direction opposite_way, const char * name, const char * description, Room * source, Room * destination) :
	Entity(name, description)
{

	type = EXIT;


}

Exit::~Exit()
{
}
