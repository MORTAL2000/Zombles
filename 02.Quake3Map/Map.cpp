#include "Map.h"
#include "Utility.h"
#include "World.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

Map::Map(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation)
	: Entity(world, path, position, rotation)
{
	std::cout << " -> Constructing Map: " << path << std::endl;
	std::fstream fin(path);
	std::string command;

	while (std::getline(fin, command))
	{
		std::vector<std::string> tokens;
		str_to_vec(command, tokens);
		// If the command type is file, then simply load the file in.		
		if ((tokens.size() == 3) && (tokens[0] == "file"))
		{
			std::cout << " -> [map][loading] pkg: " << tokens[1] << " mesh: " << tokens[2] << std::endl;
			load_map(tokens[1], tokens[2]);
		}
	}
}

Map::~Map()
{
}

void Map::load_map(const std::string& pkg_path, const std::string& bsp_path)
{
	world->device->getFileSystem()->addFileArchive(pkg_path.c_str());
	irr::scene::IAnimatedMesh *mesh = world->smgr->getMesh(bsp_path.c_str());
	irr::scene::ISceneNode *node = nullptr;
	// Set up the mesh
	if (mesh)
		node = world->smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
	// Set up the node
	if (node)
	{
		node->setPosition(position);
		node->setRotation(rotation);
	}
}