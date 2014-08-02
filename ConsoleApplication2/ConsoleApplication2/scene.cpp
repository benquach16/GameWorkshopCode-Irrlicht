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
	new Object(globals::device->getSceneManager()->addCubeSceneNode(),
		(Object::E_COMPONENTS)0x00,
		vector3df(0,0,0),
		vector3df(0,0,0));
	new Object(globals::device->getSceneManager()->addCubeSceneNode(),
		(Object::E_COMPONENTS)0x00,
		vector3df(20, 0, 0),
		vector3df(0, 0, 0));
	new Ball(
		vector3df(0, 0, 0),
		vector3df(0, 0, 0));
	camera = globals::device->getSceneManager()->addCameraSceneNode();
	camera->setPosition(vector3df(0, 100, 0));
	
	camera->setTarget(vector3df(0,0,0));
	camera->setRotation(camera->getRotation() + vector3df(0, 0, 90));

}

Scene::~Scene()
{
	for (unsigned i = 0; i < Object::allObjects.size(); i++)
	{
		delete Object::allObjects[i];
	}
}

void Scene::run()
{
	for (unsigned i = 0; i < Object::allObjects.size(); i++)
	{
		Object::allObjects[i]->run();
	}
}
