#include "Item.h"

Item::Item(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation)
	: Entity(world, path, position, rotation)
{
}


Item::~Item()
{
}
