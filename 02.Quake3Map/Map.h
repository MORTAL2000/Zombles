#ifndef ZOMBLE_MAP_H_
#define ZOMBLE_MAP_H_

#include "Entity.h"
#include <irrlicht.h>

class Map : public Entity
{
public:
	// Public members of the entity
	irr::scene::IMeshSceneNode *node;
	irr::scene::ITriangleSelector *selector;
	// Constructor
	Map(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	// Deconstructor
	~Map();
private:
	// Loads the map.
	void load_map(const std::string& pkg_path, const std::string& bsp_path);
};

#endif // ZOMBLE_MAP_H_