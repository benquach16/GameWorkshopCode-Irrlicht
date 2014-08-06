#include "stdafx.h"
#include "globals.h"
#include "player.h"


Player::Player(
	irr::core::vector3df& position,
	irr::core::vector3df& rotation,
	irr::core::vector3df& scale) 
	:
	Paddle(
	position,
	rotation,
	scale)
{
	globals::device->setEventReceiver(&handler);
}

void Player::run()
{
	if (handler.isKeyDown(irr::KEY_UP))
	{
		speed = -PADDLESPEED;
	}
	else if (handler.isKeyDown(irr::KEY_DOWN))
	{
		speed = PADDLESPEED;
	}
	else
	{
		speed = 0;
	}
	Paddle::run();
}

const bool Player::isPlayer() const
{
	return true;
}
