#ifndef ZOMBLE_ENTITY_H_
#define ZOMBLE_ENTITY_H_

#include <irrlicht.h>
#include <string>

// Predefined world
class World;

class Entity
{
protected:
	irr::core::vector3df position;
	irr::core::vector3df rotation;
	std::string path;
	World *world;
public:
	Entity(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	virtual ~Entity();
	void update();
};

#endif // ZOMBLE_ENTITY_H_

