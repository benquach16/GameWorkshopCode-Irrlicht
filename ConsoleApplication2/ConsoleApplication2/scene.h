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
	Scene();
	~Scene();
	void run();
	void aiBullshit();
protected:
	irr::scene::ICameraSceneNode *camera;
	Ball* ball;
	HUD* hud;
	Player *player;
	irr::scene::ILightSceneNode* light;
};