#pragma once

#include "scene.h"


class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();
	virtual E_SCENE_RETURN_CODE run();
	void aiBullshit();
protected:
	irr::scene::ICameraSceneNode *camera;
	Ball* ball;
	HUD* hud;
	Player *player;
	irr::scene::ILightSceneNode* light;	
	irr::scene::ILightSceneNode* light3;	
};
