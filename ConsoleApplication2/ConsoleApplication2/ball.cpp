#include "stdafx.h"
#include "globals.h"
#include "paddle.h"
#include "ball.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

Ball::Ball(
	irr::core::vector3df& position,
	irr::core::vector3df& rotation,
	irr::core::vector3df& scale) : 
	Object(
	globals::device->getSceneManager()->addSphereSceneNode(),
	(E_COMPONENTS)0x01,
	position,
	rotation,
	scale)
{

}

Ball::~Ball()
{

}


void Ball::run()
{
	for (unsigned i = 0; i < Paddle::allPaddles.size(); i++)
	{
		if (Paddle::allPaddles[i]->getBoundingBox().intersectsWithBox(getBoundingBox()))
		{
			realisticPhysics();
			//if collides
			Paddle::allPaddles[i]->takeDamage(5);
		}
	}
	if (getPosition().Z > 90 || getPosition().Z < -90)
	{
		if (rand() % 2 < 1)
		{
			vector3df newPos = getPosition();
			newPos.Z = -newPos.Z;
			setPosition(newPos);
		}
		else
		{
			realisticPhysics();
			setPosition(vector3df(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20));
		}
	}
	Object::run();
}

//protected function
void Ball::realisticPhysics()
{
	//speed = -speed;
	vector3df newRot(getRotation());
	newRot.Y += rand() % 270 + 90;
	setRotation(newRot);
}

void Ball::movement()
{
	vector3df newPosition;
	newPosition.X = sin((getRotation().Y*3.1415) / 180) * speed + getPosition().X;
	newPosition.Y = sin((getRotation().X*3.1415) / 180) * speed + getPosition().Y;
	newPosition.Z = cos((getRotation().Y*3.1415) / 180) * speed + getPosition().Z;
	setPosition(newPosition);
}
