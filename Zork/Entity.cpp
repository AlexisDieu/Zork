#include "Entity.h"
#include <iostream>

Entity::Entity(const char * name, const char * description)
{
	this->name = name;
	this->description = description;
	type = ENTITY;
}

Entity::~Entity()
{
}

void Entity::Update()
{
}

string Entity::GetName() const
{
	return name;
}
