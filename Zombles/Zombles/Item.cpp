#include "Item.h"
#include "World.h"
#include "Utility.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Item::Item(World *world, const std::string &path, irr::core::vector3df position, irr::core::vector3df rotation)
	: Entity(world, path, position, rotation)
{
	std::cout << " -> Constructing Item: " << path << std::endl;
	std::fstream fin(path);
	std::string command;

	while (std::getline(fin, command))
	{
		std::vector<std::string> tokens;
		str_to_vec(command, tokens);
		// If the command type is file, then simply load the file in.		
		if ((tokens.size() == 3) && (tokens[0] == "model"))
		{
			std::cout << " -> [map][loading] mesh: " << tokens[1] << " texture: " << tokens[2] << std::endl;
			load_model(tokens[1], tokens[2]);
		}
	}
}


Item::~Item()
{
}

void Item::load_model(const std::string& mesh_path, const std::string &texture_path)
{
	irr::scene::IAnimatedMesh *mesh = world->smgr->getMesh(mesh_path.c_str());
	if (mesh) {
		irr::scene::IAnimatedMeshSceneNode *node = world->smgr->addAnimatedMeshSceneNode(mesh);
		if (node)
		{
			node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			node->setMaterialTexture(0, world->driver->getTexture(texture_path.c_str()));
			node->setPosition(position);
			node->setRotation(rotation);
		}
	}
}
