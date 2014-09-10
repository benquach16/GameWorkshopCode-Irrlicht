#pragma once

#include "scene.h"


class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();
	virtual E_SCENE_RETURN_CODE run();

protected:
	irr::gui::IGUIStaticText *text;
	irr::gui::IGUIStaticText *secretmessage;
	irr::gui::IGUIImage *nickcage;
	irr::gui::IGUIButton *start;
	irr::gui::IGUIButton *leave;
};
