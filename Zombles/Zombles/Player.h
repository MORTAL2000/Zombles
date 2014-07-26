#ifndef ZOMBLE_PLAYER_H_
#define ZOMBLE_PLAYER_H_

#include "Entity.h"
#include "Item.h"

class Player : public Entity {
	irr::scene::ICameraSceneNode *camera;
	Item *gun;

public:
	Player(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation);
	~Player();
private:
	void camera_setup();
	void map_setup();
	void parse_config(const std::string &path);
};

#endif // ZOMBLE_PLAYER_H_