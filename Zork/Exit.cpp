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

const string & Exit::GetName(const Room * room) const
{
	return name;
}

direction Exit::GetWay() const
{
	return way;
}
direction Exit::GetOpposite_Way() const
{
	return opposite_way;
}

string Exit::GetSourceName() const
{
	return source->GetName();
}

string Exit::GetDestinationName() const
{
	return destination->GetName();
}

