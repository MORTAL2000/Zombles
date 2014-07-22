#ifndef ZOMBLE_WORLD_H_
#define ZOMBLE_WORLD_H_

#include <algorithm>
#include <vector>
#include <irrlicht.h>

class Entity;

class World
{
	std::vector<Entity*> entities;
public:
	// Irrlicht components
	irr::IrrlichtDevice *device;
	irr::video::IVideoDriver *driver;
	irr::scene::ISceneManager *smgr;

	// Constructor
	World(const std::string& file_path);
	// Destructor
	~World();
	// Run the world
	void run();
private:
	void setup_engine();
};

#endif // ZOMBLE_WORLD_H_