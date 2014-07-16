// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <irrlicht.h>
#include "scene.h"
#include "globals.h"

#pragma comment(lib, "Irrlicht.lib")

using namespace irr;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;


int _tmain(int argc, char* argv[])
{
	globals::device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480));
	Scene scene;

	
	while (globals::device->run())
	{
		globals::device->getVideoDriver()->beginScene(true, true, SColor(255, 100, 101, 140));
		scene.run();
		globals::device->getSceneManager()->drawAll();
		globals::device->getGUIEnvironment()->drawAll();

		globals::device->getVideoDriver()->endScene();
	}
	return 0;
}

