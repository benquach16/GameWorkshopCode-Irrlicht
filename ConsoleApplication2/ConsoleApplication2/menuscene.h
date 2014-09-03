#pragma once

#include "scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	virtual ~MenuScene();
	virtual E_SCENE_RETURN_CODE run();

protected:
	irr::gui::IGUIStaticText *title;
	irr::gui::IGUIButton *playGame;
	irr::gui::IGUIButton *quitGame;
};

