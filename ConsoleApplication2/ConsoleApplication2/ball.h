#pragma once

#include "object.h"

class Ball : public Object
{
public:
	Ball(irr::core::vector3df& position,
		irr::core::vector3df& rotation,
		irr::core::vector3df& scale = irr::core::vector3df(1, 1, 1));
	virtual ~Ball();

protected:

};
