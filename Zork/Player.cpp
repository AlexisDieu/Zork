#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(const char * name, const char * description, Room * room) :
	Creature(name,description,room)
{
	type = PLAYER;
}

Player::~Player()
{
}

bool Player::Movement(const string movement)
{
	Exit* exit = GetRoom()->GetExit(movement);
	return true;
}

void Player::Look() const
{
	GetRoom();
}
