#include "stdafx.h"
#include "globals.h"
#include "hud.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;

HUD::HUD()
{
	health = globals::device->getGUIEnvironment()->addStaticText(
		L"TestText",
		rect<s32>(100, 100, 300, 300));
	health->setOverrideColor(SColor(255, 255, 255, 0));

	score = globals::device->getGUIEnvironment()->addStaticText(
		L"TestText",
		rect<s32>(200, 100, 300, 300));
	score->setOverrideColor(SColor(255, 255, 255, 0));
}

HUD::~HUD()
{
	health->remove();
	score->remove();
}

void HUD::run(const Player * player)
{
	health->setText((core::stringw("Health: ") + core::stringw(player->getHealth())).c_str());
	score->setText((core::stringw("Score: ") + core::stringw(player->getScore())).c_str());
}
