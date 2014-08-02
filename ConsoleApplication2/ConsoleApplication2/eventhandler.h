#pragma once

#include <irrlicht.h>

class EventHandler : public irr::IEventReceiver
{
public:
	EventHandler();
	virtual bool OnEvent(const irr::SEvent& event);
	virtual bool isKeyDown(irr::EKEY_CODE keyCode) const;
protected:

	bool keys[irr::KEY_KEY_CODES_COUNT];
};
