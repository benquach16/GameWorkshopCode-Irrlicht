#pragma once

#include <irrlicht.h>
#include <vector>

class Object
{
public:
	static std::vector<Object*> allObjects;

	Object(irr::scene::IMeshSceneNode *mesh,
		irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale = irr::core::vector3df(1,1,1));
	~Object();

	virtual void run();
	//accessors
	const irr::core::vector3df& getPosition() const;
	const irr::core::vector3df& getRotation() const;
	const irr::core::vector3df& getScale() const;
	//mutators
	void setPosition(const irr::core::vector3df& newPosition);
	void setRotation(const irr::core::vector3df& newRotation);
	void setScale(const irr::core::vector3df& newScale);
protected:
	unsigned index;
	irr::scene::IMeshSceneNode *mesh;
};