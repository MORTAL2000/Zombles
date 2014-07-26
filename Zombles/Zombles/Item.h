#ifndef ZOMBLE_ITEM_H_
#define ZOMBLE_ITEM_H_

#include "Entity.h"

class Item :
	public Entity
{
public:
	Item(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	~Item();
	void load_model(const std::string& mesh_path, const std::string &texture_path);
};

#endif // ZOMBLE_ITEM_H_