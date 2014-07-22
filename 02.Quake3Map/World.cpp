#include "World.h"
#include "Entity.h"
#include "Player.h"
#include "Item.h"
#include "Zombie.h"
#include "Map.h"
#include "Utility.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>


World::World(const std::string& file_path)
{
	setup_engine();
	// Open the file
	std::fstream fin(file_path);
	std::string command;

	// Iterate over each line in the file.
	std::cout << "* Constructing World" << std::endl;
	while (std::getline(fin, command)) {
		// Create a vector to store the tokens, and convert the line to a string stream.
		std::vector<std::string> tokens;
		str_to_vec(command, tokens);
		
		if (tokens.size() == 4)
		{
			std::cout << " -> Entity - Type: " << tokens[0] << " File: " << tokens[1] << " Position: " << tokens[2] << " Rotation: " << tokens[3] << std::endl;
			
			// Construct the entity, and create position and rotation values.
			Entity *entity = nullptr; // NULL if using C++98
			irr::core::vector3df position = str_to_vec3df(tokens[1]);
			irr::core::vector3df rotation = str_to_vec3df(tokens[2]);
			std::string path = "../../data/";
			path += tokens[1] + ".txt";

			// Simple dispatcher for each of the valid types.
			if (tokens[0] == "player")      entity = new Player(this, path, position, rotation);
			else if (tokens[0] == "item")   entity = new Item(this, path, position, rotation);
			else if (tokens[0] == "map")    entity = new Map(this, path, position, rotation);
			else if (tokens[0] == "zombie") entity = new Zombie(this, path, position, rotation);

			// Push the entity in with the entities.
			entities.push_back(entity);
		}
		else
		{
			std::cout << " -> Entity - Malformed command, ignoring" << std::endl;
		}
	}
	std::cout << "* Constructing World Finished" << std::endl;
}

World::~World()
{
}

void World::setup_engine()
{
	// Set up the device, driver and scene manager.
	device = irr::createDevice(irr::video::EDT_DIRECT3D9, irr::core::dimension2d<irr::u32>(640, 480));
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
}

void World::run() {
	while (device->run()) {
		// If the window is active render the scene.
		if (device->isWindowActive()) {
			// Update entities
			driver->beginScene(true, true, irr::video::SColor(255, 200, 200, 200));
			smgr->drawAll();
			driver->endScene();

		}
		// Otherwise just yield the device, we don't want to waste CPU time.
		else
		{
			device->yield();
		}
	}
}