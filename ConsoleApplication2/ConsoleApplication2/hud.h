#pragma once

#include <irrlicht.h>
#include "player.h"

class HUD
{
public:
	HUD();
	~HUD();
	void run(const Player* player);

protected:
	irr::gui::IGUIStaticText * health;
	irr::gui::IGUIStaticText * score;
};
