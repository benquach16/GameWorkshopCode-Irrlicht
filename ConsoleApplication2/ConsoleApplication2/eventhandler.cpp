#include "stdafx.h"
#include "eventhandler.h"


EventHandler::EventHandler()
{
	for (unsigned i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
	{
		keys[i] = false;
	}
}


bool EventHandler::OnEvent(const irr::SEvent& event)
{
	switch (event.EventType)
	{
	case irr::EET_KEY_INPUT_EVENT:
		if (event.KeyInput.PressedDown)
		{
			keys[event.KeyInput.Key] = true;
		}
		else
		{
			keys[event.KeyInput.Key] = false;
		}
		break;
	default:
		break;
	}
	return false;
}

bool EventHandler::isKeyDown(irr::EKEY_CODE keyCode) const
{
	return keys[keyCode];
}

