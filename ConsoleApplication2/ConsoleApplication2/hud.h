#pragma once


class HUD
{
public:
	HUD();
	~HUD();
	void run();

protected:
	IGUIStaticText * text;
};
