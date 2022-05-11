#include "NPC.h"
#include <iostream>
#include <string>

NPC::NPC(const char * name, const char * description, Room * room,bool interact):
	Creature(name, description, room)
{
	this->interact = interact;
	type = NPCS;
}

NPC::~NPC()
{
}

void NPC::Interaction(std::vector<Entity*> entities)
{
	if (this->interact == true)
	{
		Item* item = NPCItem(entities);
		if (item != nullptr) 
		{
			cout << "Hi young man, if you can guest my name i can give you a present \n";
			string answer;
			cin >> answer;
			if (answer.compare(this->name) == 0)
			{
				cout << "Nice one you are really good ! \n";
				cout << "Alexis drop the "<< item->GetName() << "on the ground \n";
				item->setPlace(this->location);
			}
			else
			{
				cout << "My name is " << this->name <<" !!! \n";
				cout << "Get out of here i don't want to talk to you anymore. \n";
				this->setInteract(false);
			}
		}
		else
		{
			cout << "I have nothing to give to you \n";
		}
	}
	else
	{
		cout << "You cannot interact with him anymore.. \n";
	}
}

Item* NPC::NPCItem(std::vector<Entity*> entities)
{
	//check if there is an item on the inventory
	for (std::size_t i = 0; i < (int)entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			Item* it = (Item*)entities[i];
			if (it->place == this)
			{
				return it;
			}
		}
	}
	return nullptr;
}

void NPC::setInteract(bool interact)
{
	this->interact = interact;
}
