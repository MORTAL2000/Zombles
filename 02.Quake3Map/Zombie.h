#ifndef ZOMBLE_ZOMBIE_H_
#define ZOMBLE_ZOMBIE_H_

#include "Entity.h"
class Zombie :
	public Entity
{
public:
	Zombie(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	~Zombie();
};

#endif // ZOMBLE_ZOMBIE_H_