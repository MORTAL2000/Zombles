#ifndef ZOMBLE_PLAYER_H_
#define ZOMBLE_PLAYER_H_

#include "Entity.h"

class Player :
	public Entity
{
public:
	Player(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	~Player();
};

#endif // ZOMBLE_PLAYER_H_