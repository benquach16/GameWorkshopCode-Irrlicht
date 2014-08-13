#pragma once

#include <irrlicht.h>
#include <vector>

class Object
{
public:
	enum E_COMPONENTS
	{
		MOVEMENT = 0x01,
	};

	static std::vector<Object*> allObjects;

	Object(irr::scene::IMeshSceneNode *mesh,
		E_COMPONENTS components,
		irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale = irr::core::vector3df(1,1,1)
		);
	virtual ~Object();

	virtual void run();
	//accessors
	const irr::core::vector3df& getPosition() const;
	const irr::core::vector3df& getRotation() const;
	const irr::core::vector3df& getScale() const;
	irr::scene::IMeshSceneNode* getMesh();
	//mutators
	void setPosition(const irr::core::vector3df& newPosition);
	void setRotation(const irr::core::vector3df& newRotation);
	void setScale(const irr::core::vector3df& newScale);

	const irr::core::aabbox3df& getBoundingBox() const;
protected:
	//for movement component
	float speed;
	virtual void movement();

	E_COMPONENTS components;
	unsigned index;
	irr::scene::IMeshSceneNode *mesh;
};