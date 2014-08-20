#include "stdafx.h"
#include "wall.h"
#include "globals.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

std::vector<Wall*> Wall::allWalls;

Wall::Wall(
	irr::core::vector3df& position,
	irr::core::vector3df& rotation,
	irr::core::vector3df& scale) : 
	Object(
	globals::device->getSceneManager()->addCubeSceneNode(),
	(E_COMPONENTS)0x00,
	position,
	rotation,
	scale)
{
	setScale(vector3df(1, 100, 100));
	allWalls.push_back(this);
	index = allWalls.size() - 1;
}

Wall::~Wall()
{

}
