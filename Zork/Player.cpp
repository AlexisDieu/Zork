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

void Player::Look(std::vector<Entity*> entities) const
{
	string place = GetRoom()->GetName();
	cout << " you actual room is " + place + "\n";
	FindItem(entities);
}

void Player::Loot(std::vector<Entity*> entities,string commandInput)
{
	//check if there is an item on the map
	for (std::size_t i = 0; i < (int)entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			Item* it = (Item*)entities[i];
			if (it->place->GetName().compare(GetRoom()->GetName()) == 0)
			{
				if (it->GetName().compare(commandInput) == 0)
				{
				cout << "\n You take the " << it->GetName();
				it->setPlace(this);
				cout << "\n The item is now in your inventory ";
				}
			}
		}
	}

}

void Player::FindItem(std::vector<Entity*> entities) const
{
	//check if there is an item on the map
	for (std::size_t i = 0; i < (int)entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			Item* it = (Item*)entities[i];
			if (it->place->GetName().compare(GetRoom()->GetName()) == 0)
			{
				cout << "\nThere is an item here: " << it->GetName() <<"\n";
			}
		}
	}
}

void Player::Inventory(std::vector<Entity*> entities)
{

	//check if there is an item on the map
	for (std::size_t i = 0; i < (int)entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			Item* it = (Item*)entities[i];
			if (it->place == this)
			{
				cout << "\n Item : " + it->GetName() << "\n";
			}
		}
	}

}

void Player::Drop(std::vector<Entity*> entities,string commandInput)
{
	//check if there is an item in the inventory
	for (std::size_t i = 0; i < (int)entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			Item* it = (Item*)entities[i];
			if (it->place == this)
			{
				if (it->GetName().compare(commandInput) == 0)
				{
					cout << "\n You drop the item " << it->GetName() <<"\n";
					it->setPlace(this->GetRoom());
				}
			}
		}
	}
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
