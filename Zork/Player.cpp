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
					if (it->GetPickable() == true)
					{
						if (it->GetName().compare(commandInput) == 0)
						{
						cout << "\n You take the " << it->GetName();
						it->setPlace(this);
						cout << "\n The item is now in your inventory ";
						}
					}
					else
					{
						//check if there is an item inside the item
						for (std::size_t i = 0; i < (int)entities.size(); i++)
						{
							if (entities[i]->type == ITEM)
							{
								Item* it2 = (Item*)entities[i];
								if (it2->place->type == ITEM)
								{
									if (it2->place == it) {
										cout << "\nThere is an item in the " << it->GetName() << " \n";
										cout << "\n Do you want to take the " << it2->GetName() << " yes/no ? \n";
										string answer;
										cin >> answer;
										if (answer == "yes")
										{
											it2->setPlace(this);
											cout << "\n Item add in the inventory \n";
										}
										else if (answer == "no")
										{
											cout << "\n You let the " << it2->GetName() << " in the " << it->GetName() << " \n";
										}
										else {
											cout << "\n Answer not valid \n";
										}
									}
								}
							}
						}
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
					//give all possibility to where to drop the item if there is more than 1 option
					for (std::size_t j = 0; j < (int)entities.size(); j++)
					{
						if (entities[j]->type == ITEM)
						{
							Item* it2 = (Item*)entities[j];
							if (it2->GetPickable()==false)
							{
								cout << "\n Do you want to drop the item in " << it2->GetName() << " yes/no \n";
								string answer;
								cin >> answer;
								if (answer == "yes")
								{
									cout << "\n You drop the item " << it->GetName() << "\n";
									it->setPlace(it2);
								}
								else if (answer == "no")
								{
									cout << "\n You drop the item " << it->GetName() << "\n";
									it->setPlace(this->GetRoom());
								}
								else {
									cout << "\n Answer not valid \n";
								}

							}
						}
					}
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
