#include "stdafx.h"
#include "globals.h"
#include "ball.h"

Ball::Ball(
	irr::core::vector3df& position,
	irr::core::vector3df& rotation,
	irr::core::vector3df& scale) : 
	Object(
	globals::device->getSceneManager()->addSphereSceneNode(),
	position,
	rotation,
	scale)
{

}

Ball::~Ball()
{

}

