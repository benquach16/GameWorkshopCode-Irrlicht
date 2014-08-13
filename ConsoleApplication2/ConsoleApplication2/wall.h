#pragma once

#include "object.h"

class Wall : public Object
{
public:
	Wall(irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale);
	virtual ~Wall();

protected:

};

