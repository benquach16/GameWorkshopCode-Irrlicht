#pragma once

#include "object.h"

class Wall : public Object
{
public:
	static std::vector<Wall*> allWalls;
	Wall(irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale);
	virtual ~Wall();

protected:
	unsigned index;
};

