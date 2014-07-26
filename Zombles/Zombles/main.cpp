#include <irrlicht.h>
#include <iostream>

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

#include "World.h"

int main()
{
	World *world = new World("../Data/data/world.txt");
	world->run();

	return EXIT_SUCCESS;
}
