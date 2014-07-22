#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Map.h"
#include "World.h"

Player::Player(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation)
	: Entity(world, path, position, rotation)
{
	irr::scene::ICameraSceneNode *node = world->smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, 0, 0, 0, true, 3.f);
	// Set the nodes position and rotation
	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
	}
	// Get the selector from the map.
	if (world->entities["map"].size() == 0)
	{
		std::cout << " -> Map doesn't exist yet, invalid configuration file" << std::endl;
		exit(EXIT_FAILURE);
	}
	Map *map = dynamic_cast<Map*>(world->entities["map"].front());

	if (map->selector)
	{
		irr::scene::ISceneNodeAnimator *anim = world->smgr->createCollisionResponseAnimator(
			map->selector, node, irr::core::vector3df(30, 50, 30), irr::core::vector3df(0, -10, 0),
			irr::core::vector3df(0, 30, 0));
		node->addAnimator(anim);
		anim->drop();
	}
}


Player::~Player()
{
}
