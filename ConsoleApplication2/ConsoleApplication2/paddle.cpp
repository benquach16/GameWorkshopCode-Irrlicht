#include "stdafx.h"
#include "globals.h"
#include "paddle.h"
#include <time.h> 

using namespace irr;
using namespace core;

std::vector<Paddle*> allPaddles;

Paddle::Paddle(
	irr::core::vector3df& position,
	irr::core::vector3df& rotation,
	irr::core::vector3df& scale) :
	Object(
	globals::device->getSceneManager()->addCubeSceneNode(),
	(E_COMPONENTS)0x01,
	position,
	rotation,
	scale),
	maxHealth(100), health(100)
{
	speed = 0;
	srand(time(0));
	setScale(vector3df(rand()%3+1, rand()%3+1, rand()%3+1));
}

void Paddle::run()
{
	Object::run();
	if (!isPlayer())
	{
		runAi();
	}
}

const bool Paddle::isPlayer() const
{
	return false;
}


//protected function
void Paddle::runAi()
{
	
}

//protected function
void Paddle::movement()
{

	vector3df newPosition;
	newPosition.Z = getPosition().Z;
	newPosition.Y = getPosition().Y;
	newPosition.X = getPosition().X - speed;
	setPosition(newPosition);
}
