#ifndef ZOMBLE_ITEM_H_
#define ZOMBLE_ITEM_H_

#include "Entity.h"

class Item :
	public Entity
{
public:
	Item(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	~Item();
};

#endif // ZOMBLE_ITEM_H_