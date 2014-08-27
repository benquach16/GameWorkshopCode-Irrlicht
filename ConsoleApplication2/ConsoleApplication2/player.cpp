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
	scale),
	timeKeeping(0)
{
	handler = new EventHandler;
	globals::device->setEventReceiver(handler);
}

Player::~Player()
{

}

void Player::run()
{
	if (handler->isKeyDown(irr::KEY_UP))
	{
		speed = -PADDLESPEED;
	}
	else if (handler->isKeyDown(irr::KEY_DOWN))
	{
		speed = PADDLESPEED;
	}
	else
	{
		speed = 0;
	}
	if (timeKeeping < globals::device->getTimer()->getTime())
	{
		score++;
		timeKeeping = globals::device->getTimer()->getTime() + 1000;
	}
	Paddle::run();
}

const bool Player::isPlayer() const
{
	return true;
}

const int Player::getScore() const
{
	return score;
}
