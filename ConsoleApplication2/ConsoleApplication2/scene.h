#pragma once

#include <irrlicht.h>

#include "object.h"
#include "ball.h"
#include "eventhandler.h"

class Scene
{
public:
	Scene();
	~Scene();
	void run();

protected:
	irr::scene::ICameraSceneNode *camera;
};