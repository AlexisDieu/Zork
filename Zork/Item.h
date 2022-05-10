#ifndef __Item__
#define __Item__

#include <string>
#include "Entity.h"

using namespace std;

class Item : public Entity
{

public:

	Item(const char* name, const char* description,Entity* place);
	~Item();

	void setPlace(Entity* place);
	string GetEntity() const;
	Entity* place;


private:

};

#endif //__Item__
