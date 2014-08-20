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
	text = globals::device->getGUIEnvironment()->addStaticText(
		L"TestText",
		rect<s32>(100, 100, 300, 300));
	text->setOverrideColor(SColor(255, 255, 255, 0));
}

HUD::~HUD()
{

}

void HUD::run()
{
	
}
