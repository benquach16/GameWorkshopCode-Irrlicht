#include "stdafx.h"
#include "scene.h"
#include "globals.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;

Scene::Scene()
{
	hud = new HUD;
	player = new Player(
		vector3df(0, 0, 90),
		vector3df(0, 0, 0),
		vector3df(1, 1, 1));
	new Paddle(
		vector3df(0, 0, -90),
		vector3df(0, 0, 0),
		vector3df(1, 1, 1));
	ball = new Ball(
		vector3df(0, 0, 0),
		vector3df(0, 0, 0));
	
	Object* background = new Object(
		globals::device->getSceneManager()->addCubeSceneNode(),
		(Object::E_COMPONENTS)0x00,
		vector3df(-40, 0, 0),
		vector3df(0, 0, 0),
		vector3df(40, 0.1, 50));
		
	new Wall(
		vector3df(70, 5, 0),
		vector3df(0, 0, 0),
		vector3df(1, 1, 1));
	new Wall(
		vector3df(-70, 5, 0),
		vector3df(0, 0, 0),
		vector3df(1, 1, 1));
	background->getMesh()->setMaterialTexture(0, globals::device->getVideoDriver()->getTexture("Resources/Art/God.jpg"));
	camera = globals::device->getSceneManager()->addCameraSceneNode();
	camera->setPosition(vector3df(0, 100, 0));
	
	camera->setTarget(vector3df(0,0,0));
	camera->setRotation(camera->getRotation() + vector3df(0, 0, 90));

	globals::device->getSceneManager()->setAmbientLight(SColor(64,128,64,64));
	light = globals::device->getSceneManager()->addLightSceneNode();
	light->setPosition(camera->getPosition());
	light->setRadius(200);
	
	ILightSceneNode *light2 = globals::device->getSceneManager()->addLightSceneNode(
		0,
		vector3df(25, 25, 25),
		SColor(255,0,255,0));
	light2->setRadius(200);
		
}

Scene::~Scene()
{
	for (unsigned i = 0; i < Object::allObjects.size(); i++)
	{
		delete Object::allObjects[i];
	}
	delete hud;
}

void Scene::run()
{
	light->setPosition(camera->getPosition() + rand() % 300 - 150);

	for (unsigned i = 0; i < Object::allObjects.size(); i++)
	{
		Object::allObjects[i]->run();
	}
	if (player && !player->isDead())
		hud->run(player);
	else
	{
		player = 0;
	}
	aiBullshit();
	
}

void Scene::aiBullshit()
{
	for (unsigned i = 0; i < Paddle::allPaddles.size(); i++)
	{
		if (Paddle::allPaddles[i]->isDead())
		{
			delete Paddle::allPaddles[i];
			continue;
		}
		if (!Paddle::allPaddles[i]->isPlayer() &&
			Paddle::allPaddles[i]->getPosition().getDistanceFrom(ball->getPosition()) < 20)
		{
			//do bullshit
			vector3df newPos = Paddle::allPaddles[i]->getPosition();
			newPos.Z = -newPos.Z;
			Paddle::allPaddles[i]->setPosition(newPos);
		}

	}
}
