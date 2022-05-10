#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(const char * name, const char * description, Room * room) :
	Creature(name,description,room)
{
	type = PLAYER;
	location = room;
}

Player::~Player()
{
}

bool Player::Movement(direction movement, std::vector<Entity*> entities)
{
	Exit* exit = location->GetExit(this->GetRoom()->GetName(),movement,entities);
	this->Update(exit);
	return true;
}

void Player::Look() const
{
	string place = GetRoom()->GetName();
	cout << " you actual room is " + place + "\n";
}

Room * Player::GetRoom() const
{
	return location;
}

void Player::Update(Exit * exit)
{
	//verify if the actual room of the player is the source or the destination then give the other one
	//to update the room where the player is
	if (exit != nullptr) 
	{
		if (this->location->GetName().compare(exit->source->GetName()) == 0)
		{
			this->location = exit->destination;
		}
		else if (this->location->GetName().compare(exit->destination->GetName()) == 0)
		{
			this->location = exit->source;
		}
	}
}
