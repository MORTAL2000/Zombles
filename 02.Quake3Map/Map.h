#ifndef ZOMBLE_MAP_H_
#define ZOMBLE_MAP_H_

#include "Entity.h"
#include <irrlicht.h>

class Map : public Entity
{

public:
	Map(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	~Map();
private:
	void load_map(const std::string& pkg_path, const std::string& bsp_path);
};

#endif // ZOMBLE_MAP_H_