#include "stdafx.h"
#include "globals.h"
#include "menuscene.h"


using namespace irr;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;

MenuScene::MenuScene()
{
	bkg = globals::device->getGUIEnvironment()->addImage(
		globals::device->getVideoDriver()->getTexture("Resources/Art/bkg.jpg"), position2d<s32>(0, 0), false);	
	bkg->setMaxSize(dimension2du(globals::screenX, globals::screenY));
	bkg->setScaleImage(true);
	IGUIFont *largeFont = globals::device->getGUIEnvironment()->getFont("Resources/Font/verdana_large.xml");
	title = globals::device->getGUIEnvironment()->addStaticText(
		L"Pong Remixed",
		rect<s32>(globals::screenX/2-50, globals::screenY/2-200, globals::screenX/2+50, globals::screenY/2-100));
	title->setOverrideFont(largeFont);


	playGame = globals::device->getGUIEnvironment()->addButton(
		rect<s32>(globals::screenX / 2 - 50, globals::screenY / 2 - 100, globals::screenX / 2 + 50, globals::screenY / 2 - 50)
		);
	playGame->setText(L"Play Game");

	quitGame = globals::device->getGUIEnvironment()->addButton(
		rect<s32>(globals::screenX / 2 - 50, globals::screenY / 2, globals::screenX / 2 + 50, globals::screenY / 2 + 50)
		);
	quitGame->setText(L"Quit Game");



}


MenuScene::~MenuScene()
{
	title->remove();
	playGame->remove();
	quitGame->remove();
	bkg->remove();
}

Scene::E_SCENE_RETURN_CODE MenuScene::run()
{
	if (playGame->isPressed())
	{
		return Scene::SWITCH_TOTUTORIAL;
	}
	if (quitGame->isPressed())
	{
		return Scene::EXIT_GAME;
	}
	return Scene::DONOTHING;
}
