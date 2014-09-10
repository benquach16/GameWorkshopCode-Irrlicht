#include "stdafx.h"
#include "tutorialscene.h"
#include "globals.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;

TutorialScene::TutorialScene()
{
	nickcage = globals::device->getGUIEnvironment()->addImage(
		globals::device->getVideoDriver()->getTexture("Resources/Art/God.jpg"), position2d<s32>(0, 0), false);
	
	nickcage->setMaxSize(dimension2du(500, 500));
	nickcage->setScaleImage(true);
	nickcage->setVisible(false);	

	IGUIFont *largeFont = globals::device->getGUIEnvironment()->getFont("Resources/Font/verdana_large.xml");
	text = globals::device->getGUIEnvironment()->addStaticText(
		L"Use the up and down arrow keys to move your paddle! Avoid the balls! Get as high score as possible! Yay!",
		rect<s32>(globals::screenX/2-200, globals::screenY/2-200, globals::screenX/2+200, globals::screenY/2));
	text->setOverrideFont(largeFont);	
   	start = globals::device->getGUIEnvironment()->addButton(
		rect<s32>(globals::screenX / 2 - 50, globals::screenY / 2, globals::screenX / 2 + 50, globals::screenY / 2 + 100)
		);
	start->setText(L"Yeah, lemme play!");

   	leave = globals::device->getGUIEnvironment()->addButton(
		rect<s32>(globals::screenX / 2 - 50, globals::screenY / 2 + 120, globals::screenX / 2 + 50, globals::screenY / 2 + 220)
		);
	leave->setText(L"No, I'm too scared!");


		secretmessage = globals::device->getGUIEnvironment()->addStaticText(
		L"Do not be afraid",
		rect<s32>(globals::screenX/2-200, globals::screenY/2+120, globals::screenX/2+200, globals::screenY/2 + 220));
		secretmessage->setOverrideColor(SColor(255, 255, 0, 0));
	secretmessage->setOverrideFont(largeFont);	
	secretmessage->setVisible(false);
}

TutorialScene::~TutorialScene()
{
	text->remove();
	start->remove();
	secretmessage->remove();
	nickcage->remove();
	leave->remove();
}

Scene::E_SCENE_RETURN_CODE TutorialScene::run()
{
	if (start->isPressed())
	{
		return Scene::SWITCH_TOGAME;
	}
	if (leave->isPressed())
	{
		secretmessage->setVisible(true);
		nickcage->setVisible(true);
		leave->setVisible(false);
	}
	return Scene::DONOTHING;
}
