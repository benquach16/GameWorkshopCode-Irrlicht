#include "stdafx.h"
#include "globals.h"
#include "paddle.h"
#include <time.h> 

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

std::vector<Paddle*> Paddle::allPaddles;

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
	allPaddles.push_back(this);
	index = allPaddles.size() - 1;
}

Paddle::~Paddle()
{
	//do EXPLOSIONS

	scene::IParticleSystemSceneNode *particleSys;
	particleSys = globals::device->getSceneManager()->addParticleSystemSceneNode(false, 0, -1, getPosition());
	scene::IParticleEmitter *em = particleSys->createPointEmitter(
		vector3df(0, 0, 0),
		2000, 4000,
		SColor(255, 255, 255, 255),
		SColor(255, 255, 255, 255),
		1000,
		2000,
		0,
		dimension2df(5, 5),
		dimension2df(15, 15));
	particleSys->setEmitter(em);
	IParticleAffector *af = particleSys->createAttractionAffector(getPosition(), -100000.f);
	particleSys->addAffector(af);
	af->drop();
	em->drop();

	allPaddles[index] = allPaddles.back();
	allPaddles[index]->index = index;
	allPaddles.pop_back();
}

void Paddle::run()
{
	Object::run();
	if (!isPlayer())
	{
		runAi();
	}
}

void Paddle::takeDamage(int damage)
{
	health -= damage;
	setScale(vector3df(rand() % 3 + 1, rand() % 3 + 1, rand() % 3 + 1));
}

const bool Paddle::isPlayer() const
{
	return false;
}


//protected function
void Paddle::runAi()
{
	//transitions
	switch (currentState)
	{
		case STATE_INIT:
			currentState = STATE_DODGE;
			break;
		case STATE_DODGE:
			if (health > 0)
				currentState = STATE_DODGE;
			else
				currentState = STATE_DIE;
			break;
		case STATE_DIE:
			break;
		default:
			currentState = STATE_INIT;
			break;
	}

	//actions
	switch (currentState)
	{
		case STATE_INIT:
			break;
		case STATE_DODGE:
			if (rand() % 10 < 5)
				speed = PADDLESPEED;
			else
				speed = -PADDLESPEED;
			break;
		case STATE_DIE:
			break;
	}
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
