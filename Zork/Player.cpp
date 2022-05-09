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
	cout << "movement\n";
	Exit* exit = location->GetExit(this->GetRoom()->GetName(),movement,entities);
	return true;
}

void Player::Look() const
{
	GetRoom();
}

Room * Player::GetRoom() const
{
	return location;
}
