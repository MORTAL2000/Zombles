#include "Player.h"
#include "World.h"

Player::Player(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation)
	: Entity(world, path, position, rotation)
{
	irr::scene::ICameraSceneNode *node = world->smgr->addCameraSceneNodeFPS();
	// Set the nodes position and rotation
	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
	}
}


Player::~Player()
{
}
