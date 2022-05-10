#include "Item.h"

Item::Item(const char * name, const char * description, bool pickable, Entity* place)
	:Entity(name,description)
{
	type = ITEM;
	this->pickable = pickable;
	this->place = place;
}

Item::~Item()
{
}

void Item::setPlace(Entity * place)
{
	this->place = place;
}

string Item::GetEntity() const
{
	return place->GetName();
}

bool Item::GetPickable() const
{
	return pickable;
}
