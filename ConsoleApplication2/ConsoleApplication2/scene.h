#pragma once

#include <irrlicht.h>

#include "object.h"
#include "ball.h"
#include "player.h"
#include "wall.h"
#include "hud.h"
#include "eventhandler.h"

class Scene
{
public:
	enum E_SCENE_RETURN_CODE
	{
		DONOTHING=0,
		EXIT_GAME,
		SWITCH_TOGAME,
		SWITCH_TOMENU

	};
	Scene();
	virtual ~Scene();
	virtual E_SCENE_RETURN_CODE run() = 0;

protected:

};