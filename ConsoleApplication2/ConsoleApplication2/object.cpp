#include "stdafx.h"
#include "object.h"
#include "globals.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

std::vector<Object*> Object::allObjects;

Object::Object(
	irr::scene::IMeshSceneNode *mesh,
	E_COMPONENTS components,
	irr::core::vector3df& position,
	irr::core::vector3df& rotation,
	irr::core::vector3df& scale) :
	mesh(mesh), speed(0.2f), components(components)
{
	mesh->setPosition(position);
	mesh->setRotation(rotation);
	mesh->setScale(scale);


	mesh->setDebugDataVisible(true);
	Object::allObjects.push_back(this);
	index = Object::allObjects.size() - 1;
}

//destructor
Object::~Object()
{
	allObjects[index] = allObjects.back();
	allObjects[index]->index = index;
	allObjects.pop_back();
}

void Object::run()
{
	//setRotation(getRotation() + vector3df(5, 5, 0));
	if (components & MOVEMENT)
	{
		movement();
		
	}
}

const vector3df& Object::getPosition() const
{
	return mesh->getPosition();
}

const vector3df& Object::getRotation() const
{
	return mesh->getRotation();
}

const vector3df& Object::getScale() const
{
	return mesh->getScale();
}

irr::scene::IMeshSceneNode *Object::getMesh()
{
	return mesh;
}

void Object::setPosition(const vector3df& newPosition)
{
	mesh->setPosition(newPosition);
}

void Object::setRotation(const vector3df& newRotation)
{
	mesh->setRotation(newRotation);
}

void Object::setScale(const vector3df& newScale)
{
	mesh->setScale(newScale);
}

const irr::core::aabbox3df Object::getBoundingBox() const
{
	aabbox3df ret = mesh->getBoundingBox();
	ret.MaxEdge += getPosition();
	ret.MinEdge += getPosition();
	return ret;
}

//protected functions
void Object::movement()
{
	vector3df newPosition;
	newPosition.X = sin((getRotation().Y*3.1415) / 180) * speed + getPosition().X;
	newPosition.Y = sin((getRotation().X*3.1415) / 180) * speed + getPosition().Y;
	newPosition.Z = cos((getRotation().Y*3.1415) / 180) * speed + getPosition().Z;
	setPosition(newPosition);
}
